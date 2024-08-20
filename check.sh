#!/bin/bash

FILES=($(ls test_maps))

for file in "${FILES[@]}"
do
    echo "$file"
    ./fdf ./test_maps/"$file" &
    read -p "Press Enter to display the next file: " 
done

PS=$(ps | grep fdf | sed "s/^[ ]*\([0-9]*\).*/\1/g" | tr '\n' ' ')
kill ${PS}