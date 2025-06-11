#!/usr/bin/env bash

source ./config.sh

# Helper: Create temp file
TMP_FILE=$(mktemp)

# Create folders if not exist
mkdir -p "$PROJECT_OBJ" "$PROJECT_BIN" "$LIBS_OBJECT"

### 1. Select libraries to compile
LIB_FILES=()
for file in "$PROJECT_LIBS"/*.c; do
    fname=$(basename "$file")
    LIB_FILES+=("$fname" "" off)
done

dialog --checklist "Select library files to compile:" 15 50 6 "${LIB_FILES[@]}" 2>"$TMP_FILE"
selected_libs=$(<"$TMP_FILE")
if [[ -z "$selected_libs" ]]; then
    echo "No libraries selected. Exiting."
    exit 1
fi

# Compile selected libraries
for lib in $selected_libs; do
    lib="${lib//\"/}" # remove quotes
    echo "Compiling $lib"
    gcc -c "$PROJECT_LIBS/$lib" -I "$PROJECT_HEADERS"
    if [[ $? -ne 0 ]]; then
        echo "Failed to compile $lib"
        exit 1
    fi
done

# Move .o files
mv ./*.o "$PROJECT_OBJ/" 2>/dev/null

# Create static library
ar rcs "$LIBS_OBJECT/libproject.a" "$PROJECT_OBJ"/*.o

### 2. Select main source file
MAIN_FILES=()
for file in "$PROJECT_SRC"/*.c; do
    fname=$(basename "$file")
    MAIN_FILES+=("$fname" "" off)
done

dialog --radiolist "Select main source file to compile:" 15 50 6 "${MAIN_FILES[@]}" 2>"$TMP_FILE"
main_file=$(<"$TMP_FILE")
if [[ -z "$main_file" ]]; then
    echo "No main file selected. Exiting."
    exit 1
fi

output_file="${main_file%%.*}" # e.g., main from main.c

echo "Compiling main source: $main_file"
gcc "$PROJECT_SRC/$main_file" -I "$PROJECT_HEADERS" -L "$LIBS_OBJECT" -l project -o "$PROJECT_BIN/$output_file"

if [[ $? -eq 0 ]]; then
    echo "Build successful. Output: $PROJECT_BIN/$output_file"
else
    echo "Build failed."
    exit 1
fi

rm "$TMP_FILE"
