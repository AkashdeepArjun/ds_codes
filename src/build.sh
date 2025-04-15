#!/usr/bin/bash

source './config.sh'

echo "compiling libraries"
gcc -c $PROJECT_LIBS/*.c

if [[ $? -eq 0 ]]; then
    echo " COMPILED LIBRARY SUCCESS MOVING  OBJECTS TO OBJECT FOLDER "
    if [[ -d $PROJECT_OBJ ]]; then
        mv ./*.o $PROJECT_OBJ/
    else
        mkdir $PROJECT_OBJ
        mv *.o $PROJECT_OBJ
    fi
    echo "LIBRARY COMPILE SUCCESS"
fi
echo "MAKING SHARED OBJECT DIRECTORY..."
if [[ ! -d $LIBS_OBJECT ]]; then
    mkdir $LIBS_OBJECT
    if [[ $? -eq 0 ]]; then
        echo "SHARED LIB FOLDER CREATED"
    fi
else
    echo "making lib file....."
    ar rcs $LIBS_OBJECT/'libproject.a' $PROJECT_OBJ/*.o

    if [[ $? -eq 0 ]]; then
        echo "SHARED LIB FILE CREATION SUCCESS"

    fi

fi

# read -p "ente source file " src_file
# echo "select source file "
#
# src_file=$(zenity --file-selection)
#
# if [[ -z $src_file ]]; then
#     echo "please select source file again"
#     exit
#
# fi

# if [[ ! -d $PROJECT_SRC ]]; then
#     mkdir -p $PROJECT_SRC
#     echo "src folder created with status code {$?}"
# fi
#
# if [[ ! -d $PROJECT_BIN ]]; then
#     mkdir -p $PROJECT_BIN
#     echo "bin folder created with status code {$?}"
# fi

file_proper=$PROJECT_SRC/"${src_file}.c"
#
# echo "you have specified $file_proper"
# if [[ ! -e $file_proper ]]; then
#     echo "you have not specified valid file"
#     exit
# fi
# read -p "enter output file name" output_file
#
# if [[ -z $output_file ]]; then
#     echo "please enter valid  output file name"
#     exit
#
# fi
#
if [[ ! -d $PROJECT_SRC ]]; then
    echo " no source file folder exist please add some source files for cpmpile"
    exit -1
fi

echo "compiling source "

src_files=($(ls ${PROJECT_SRC}))

for file in ${src_files[@]}; do

    output_file="${file%%.*}"
    echo "file found ${output_file}"
    gcc $PROJECT_SRC/$file -I $PROJECT_HEADERS -L $LIBS_OBJECT -l project -o $PROJECT_BIN/$output_file
    if [[ $? -eq 0 ]]; then
        echo "Build source file ${output_file} Success"
    else
        echo "build error please  try recompiling again "
        exit -1
    fi

done

# gcc $src_file -I $PROJECT_HEADERS -L $LIBS_OBJECT -l project -o $PROJECT_BIN/$output_file

if [[ $? -eq 0 ]]; then
    echo "BUILD PROJECT SUCCESS"
fi
