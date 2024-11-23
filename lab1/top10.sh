
#!/bin/bash
#Script name: top10.sh
#Name : Pauline Nyandusi
#Date : September 19th 2023
#Summary: 


#check if there is an argument provided
if [[ $# -eq 0 ]]; then
    echo "No argument provided"
fi

if [[ ! -r "$1" ]]; then
    echo "Error, file is not readable."
    exit 1
fi

echo "| Area  | Doses administered  |"
echo  "| :------ | --------: |"

grep "All" vaccine_data_us.csv |cut -d, -f 2,10 | sort -t',' -k2,2 -nr | head -n 10 | sed -e 's/^/|/' -e 's/$/|/' -e 's/,/|/g'



