export PROJECT_SRC="src"
export PROJECT_HEADERS="header"
export PROJECT_LIBS="libs"
export PROJECT_OBJ="obj_files"
export LIBS_OBJECT="libs_object"
export PROJECT_SNIPPETS="snippets"
export PROJECT_BIN="bin"

if [[ ! -d $PROJECT_SNIPPETS ]]; then
    mkdir -p $PROJECT_SNIPPETS
    if [[ $? -eq 0 ]]; then
        echo "snippets directory initialized"
    fi

fi
