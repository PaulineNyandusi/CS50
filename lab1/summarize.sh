#!/bin/bash
#Script name: summarize.sh
#Name : Pauline Nyandusi
#Date : September 19th 2023
#Summary: 

if [[ $# -eq 0 ]]; then
    echo "No argument provided">&2
fi

#loop through all arguments
for pathname in "$@"; do 
    #check if its readable
    if [[ ! -r "$pathname" ]]; then
        echo "Error, not readable"
        continue
    fi 

    if [[ "$pathname" == *.sh ]]; then 
        language="bash"

    elif [[ "$pathname" == *.c || "$pathname" == *.h ]]; then
        language="c"

    else
        continue
    fi

    echo "## $(basename $pathname)"
    echo '```'"$language"

    sed '/^$/q;/^#!/d;p' "$pathname"

    echo '```'

done


