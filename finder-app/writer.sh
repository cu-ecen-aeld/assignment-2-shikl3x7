#!/bin/bash

file_name=$1
write_string=$2

if [ $# -eq 2 ];
then
    if [ ! -d "$file_name" ];
    then
	    mkdir -p $(dirname "$file_name")  
            touch "$file_name" | echo "$write_string" > "$file_name"		
    else
            touch "$file_name" | echo "$write_string" > "$file_name"		
    fi
else
   echo "More than or less than 2 arguments provided"
   exit 1
fi
