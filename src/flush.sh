#!/usr/bin/bash

source './config.sh'

rm -rf $PROJECT_BIN/*

if [[ $? -eq 0 ]]; then
    echo "removed $PROJECT_BIN"
fi
