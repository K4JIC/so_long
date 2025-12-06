#!/bin/bash

for file in "$1"/* "$1"/.* ; do
    if [ -f "$file" ]; then
        echo "./so_long $file"
        valgrind --leak-check=full --show-leak-kinds=all -q ./so_long "$file"
		echo ''
    fi
done
