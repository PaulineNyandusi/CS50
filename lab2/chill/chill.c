/*

File name: chill.c
Name : Pauline Nyandusi
Date : Tuesday sept 26
Summary: A cfile that calculates "wind chill" based on the current temperature and wind speed. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

bool numberChecker (const char *str); //Function Declaration

double windChillCalculation(double temperature, double velocity); // Function declaration

int main(int argc, char *argv[]) {
    // If no command-line arguments are provided
    if (argc == 1) {
        
        // Print a table header for temperature, wind speed, and wind chill
        printf("  Temp  Wind    Chill\n");
        printf(" -----  -----   -----\n");

        // Iterate through a range of temperatures and wind speeds to calculate and print the wind chill
        for (double temperature = -10; temperature <= 40; temperature = temperature + 10) {
            for (double velocity = 5; velocity <= 15; velocity += 5) {
                // Print the temperature, wind speed, and calculated wind chill in each row
                printf("%5.1f    %5.1f    %5.1f\n", temperature, velocity, windChillCalculation(temperature, velocity));
            }

            // Print a newline after each set of wind speeds for a given temperature
            printf("\n");
        }
    }

    // If one command-line argument is provided (temperature)
    else if (argc == 2) {
        // Check if the provided argument is a valid number
        if (!numberChecker(argv[1])) {
            // Print an error message if the argument is not a valid number
            fprintf (stderr, "Incorect Format: Numbers and not characters are required\n");
            return 4;
        }

        // Convert the argument to a floating-point number
        double temperature = atof(argv[1]);

        // Validate the temperature range
        if (temperature > -99 && temperature < 50) {
            printf("  Temp  Wind    Chill\n");
            printf(" -----  -----   -----\n");
            for (double velocity = 5; velocity <= 15; velocity += 5)
            {
                printf("%5.1f    %5.1f    %5.1f\n", temperature, velocity, windChillCalculation(temperature, velocity));
            }
        }

        else {
            if (temperature < -99) {
                printf("Temperature must be greater than 99\n");
                return 1;
            }

            else if (temperature > 50) {
                printf("Temperature must be less than 50\n");
                return 1;
            }
        }
    }

    // If two command-line arguments are provided (temperature and wind speed)
    else if (argc == 3) {
        double temperature = atof(argv[1]);
        double velocity = atof(argv[2]);

        if (velocity > 0.5 && velocity < 231) {
            if (temperature > -99 && temperature < 50) {
                printf("%5.1f    %5.1f    %5.1f\n", temperature, velocity, windChillCalculation(temperature, velocity));
            }

            else {
                if (temperature < -99)
                {
                    printf("Temperature must be greater than -99\n");

                    return 1;
                }
                else if (temperature > 50)
                {
                    printf("Temperature must be less than 50\n");
                    return 1;
                }
            }
        }

        else {
            if (velocity < 0.5) {
                printf("Wind velocity must be greater than 0.5 MPH\n");
                if (temperature < -99) {
                    printf("Temperature must be greater than -99\n");
                    return 1;
                }

                else if (temperature > 50) {
                    printf("Temperature must be less than 50\n");
                    return 1;
                }
                return 2;
            }

            else if (velocity > 231) {
                printf("Wind velocity must be less than 231 MPH\n");

                if (temperature < -99) {
                    printf("Temperature must be greater than -99\n");

                    return 1;
                }

                else if (temperature > 50) {
                    printf("Temperature must be less than 50\n");
                    return 1;
                }
                return 2;
            }
        }
    }

    else {
        printf("usage: Too many arguments\n");
        return 3;
    }

    return 0; // exit the program properly
}

/*
    This function calculates the wind chill factor given a specific temperature and wind velocity.
    It implements the formula for wind chill calculation and returns the resulting value.
*/
double windChillCalculation(double temperature, double velocity)
{
    // T is the temperature in degrees Fahrenheit (when less than 50 and greater than -99)
    // V is the wind velocity in miles per hour.

    return 35.74 + 0.6215 * temperature - 35.75 * pow(velocity, 0.16) + 0.4275 * temperature * pow(velocity, 0.16);
}

/*
    This function checks if the provided string contains only digits or a decimal point or more than one decimal point.
*/


bool numberChecker(const char *str){
    // Check if the string is null or empty, return false
    if (str == NULL || *str == '\0'){
        return false;
    }

    int counterDecimalPoint = 0;  // Counter for decimal points

    while (*str != '\0') {
        if (isdigit((unsigned char)*str) || *str == '.') {
            if (*str == '.') {
                counterDecimalPoint++;
                // Check if more than one decimal point is present
                if (counterDecimalPoint > 1) {
                    return false;
                }
            }
            str++; 
        }
        else {
            return false;
        }
    }

    return true;
}
