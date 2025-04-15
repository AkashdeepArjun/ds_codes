#!/usr/bin/bash
source './config.sh'
read -p "enter file name" f_name

if [[ -z $f_name ]]; then
    echo "please enter file name"
    exit
fi

if [[ ! -d $PROJECT_SRC ]]; then
    echo "making directories ....."
    mkdir -p $PROJECT_SRC
    echo "src directory done with status {$?}"
fi

cp $PROJECT_SNIPPETS/sample.c $PROJECT_SRC/$f_name.c

if [[ $? -eq 0 ]]; then
    echo " source file ${f_name} created!!"
fi
