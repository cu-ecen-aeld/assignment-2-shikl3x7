#!/bin/bash

file_directory=$1
search_string=$2

if [ $# -eq 2 ] ;
then
    if [ -d "$file_directory" ];
    then 
       number_of_files=$(ls $file_directory | wc -l ) 
       number_string_matched=$(grep -r "$search_string" "$file_directory" | wc -l)
       echo "The number of files are $number_of_files and the number of matching lines are $number_string_matched"
    else
       echo "Given path $file_directory does not seem to be a directory in the system"
       exit 1	
    fi	    
else
    echo "Missing some arguments or extra arguments provided"
    exit 1

fi
