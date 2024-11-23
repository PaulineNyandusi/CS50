# Pauline Nyandusi
## CS50 Fall 2023, Lab 1

GitHub username:PaulineNyandusi

##Problem B, Creating a symbolic link.
``` bash
 ln -s ~/cs50-dev/shared/students_files/COVID-19/data_tables/vaccine_data/us_data/hourly/vaccine_data_us.csv ./vaccine_data_us.csv
```

##Problem C, A single bash command or pipeline to print only the header line of the spreadsheet.

``` bash
head -n 1 vaccine_data_us.csv
```

##Problem D, Extending the bash command to print only the header line of the spreadsheet, but to present the header fields one per line, instead of a single comma-separated line. For example, instead of seeing Name,Class,Major you would see

``` bash
head -n 1 vaccine_data_us.csv | tr ',' '\n'
```

##Problem E, a single bash command or pipeline to print only the "New Hampshire" line(s) of the spreadsheet.

``` bash
 grep "New Hampshire" vaccine_data_us.csv
 ```


##Problem F, a single bash command or pipeline to print only the rows representing All vaccine types and only the Province_State and Doses_admin columns, separated by a comma. (Note Province_State includes some names that are neither a province nor a state; for generality, let's call those 'areas'.)

``` bash
 grep "All" vaccine_data_us.csv |cut -d, ',' -f 2,10 vaccine_data_us.csv 
 ```

 ##Problem G, A Extend that bash commandline to print the top-10 areas in terms of all types of doses administered, in decreasing order of the number of doses administered. Each line of output should contain the area name and the number of doses, separated by a comma.

 ``` bash
grep "All" vaccine_data_us.csv |cut -d, -f 2,10 | sort -t',' -k2,2 -nr | head -n 10
```

##Problem H, Extend that bash commandline to print the top-10 areas in terms of all types of doses administered, in decreasing order of the number of doses administered. Each line of output should contain the area name and the number of doses, separated by a comma.

``` bash
grep "All" vaccine_data_us.csv |cut -d, -f 2,10 | sort -t',' -k2,2 -nr | head -n 10 | sed -e 's/^/|/' -e 's/$/|/' -e 's/,/|/g'
```



