#!/usr/bin/bash
source './config.sh'
read -p "enter file_name" f_name

if [[ -z $f_name ]]; then
    echo "file name cant be empty"
else
    if [[ -d $PROJECT_HEADERS ]]; then
        touch $PROJECT_HEADERS/$f_name.h
    else
        mkdir -p $PROJECT_HEADERS
        touch $PROJECT_HEADERS/$f_name.h

    fi
    echo "header file created successfully!!!"
fi
