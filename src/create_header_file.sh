#!/usr/bin/bash
source './config.sh'
read -p "enter file name" f_name

if [[ -z $f_name ]]; then
    echo "please enter file name"
    exit
fi

if [[ ! -d $PROJECT_HEADERS ]]; then
    echo "making directories ....."
    mkdir -p $PROJECT_HEADERS
    echo "header directory done with status {$?}"
fi

cp $PROJECT_SNIPPETS/sample_header.h $PROJECT_HEADERS/$f_name.h

if [[ $? -eq 0 ]]; then
    echo " header file ${f_name} created!!"
fi
