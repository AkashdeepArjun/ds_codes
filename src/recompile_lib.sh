#!/usr/bin/bash

source './config.sh'

echo "recompiling libraris....."

if [[ ! -d $PROJECT_LIBS ]]; then
    echo " no library folder found "
    exit -1
else
    echo " LIBRARY folder exists .."
    if [[ ! -d $PROJECT_OBJ ]]; then
        mkdir $PROJECT_OBJ
        if [[ $? -eq 0 ]]; then
            gcc -c $PROJECT_LIBS/*.c
            if [[ $? -eq 0 ]]; then

                mv ./*.o $PROJECT_OBJ
                if [[ $? -eq 0 ]]; then
                    echo "recompile library success"
                fi
            fi

        fi
    else
        gcc -c $PROJECT_LIBS/*.c
        if [[ $? -eq 0 ]]; then

            mv ./*.o $PROJECT_OBJ
            if [[ $? -eq 0 ]]; then
                echo "recompile library success"
            fi
        fi
    fi

fi
echo "rebuilding library....."

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
