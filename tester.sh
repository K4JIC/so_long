#!/bin/bash

for file in ./testmap/*; do
    if [ -f "$file" ]; then
        echo "./so_long $file"
        ./so_long "$file"
		echo ''
    fi
done
