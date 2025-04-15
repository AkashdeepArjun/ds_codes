#!/usr/bin/bash
source './config.sh'
read -p "enter file_name" f_name

if [[ -z $f_name ]]; then
    echo "file name cant be empty"
else
    if [[ -d $PROJECT_LIBS ]]; then
        touch $PROJECT_LIBS/$f_name.c
    else
        mkdir -p $PROJECT_LIBS
        touch $PROJECT_LIBS/$f_name.c
    fi
    echo "lib file created successfully!!!"

fi
