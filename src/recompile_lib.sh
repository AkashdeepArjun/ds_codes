#!/usr/bin/env bash

source ./config.sh
TMP_FILE=$(mktemp)

# Check for lib source directory
if [[ ! -d $PROJECT_LIBS ]]; then
    echo "No library folder found"
    exit 1
fi

mkdir -p "$PROJECT_OBJ"
mkdir -p "$LIBS_OBJECT"

# Step 1: Select libraries to compile
LIB_FILES=()
for file in "$PROJECT_LIBS"/*.c; do
    fname=$(basename "$file")
    LIB_FILES+=("$fname" "" off)
done

dialog --checklist "Select library files to recompile:" 15 50 6 "${LIB_FILES[@]}" 2>"$TMP_FILE"
selected_libs=$(<"$TMP_FILE")
if [[ -z "$selected_libs" ]]; then
    echo "No libraries selected. Exiting."
    rm "$TMP_FILE"
    exit 1
fi

# Step 2: Compile selected files
for lib in $selected_libs; do
    lib="${lib//\"/}" # Remove quotes
    echo "Compiling $lib"
    gcc -c "$PROJECT_LIBS/$lib" -I "$PROJECT_HEADERS"
    if [[ $? -ne 0 ]]; then
        echo "Compilation failed for $lib"
        rm "$TMP_FILE"
        exit 1
    fi
done

mv ./*.o "$PROJECT_OBJ/" 2>/dev/null

# Step 3: Rebuild static library
echo "Rebuilding static library..."
ar rcs "$LIBS_OBJECT/libproject.a" "$PROJECT_OBJ"/*.o

if [[ $? -eq 0 ]]; then
    echo "Static library rebuilt successfully."
else
    echo "Library build failed."
    rm "$TMP_FILE"
    exit 1
fi

rm "$TMP_FILE"
