/*
histo.c

Pauline Nyandusi

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main() {

    //main function, that reads from a stdin

    //number of b ins in our histogram must be 16 at all times

    int binSize = 1;
    int const NUMBER_OF_BINS = 16;
    int lowerBound = 0;
    int upperBound = NUMBER_OF_BINS;
    int array[16] = {0};
    int numberLocation;

    int value; // whatever from stdin


    printf("%d bins of size %d for range [%d,%d] \n", NUMBER_OF_BINS, binSize, lowerBound, upperBound);


    while (scanf("%d", &value) != EOF) {
        if (value > 0){
         
            while (value >=  upperBound) { 

                binSize = binSize * 2;
                upperBound = upperBound * 2;

                printf("%d bins of size %d for range [%d,%d] \n", NUMBER_OF_BINS, binSize, lowerBound, upperBound);


                //com press the current 16 bins to 8 bins
                int idx = 0;

                for (int i = 0; i < NUMBER_OF_BINS - 1; i += 2){

                    int tempArray = array[i] + array[i + 1];
                    array[i] = tempArray;
                    idx ++;
            
                }

                for (int i = (NUMBER_OF_BINS / 2); i < NUMBER_OF_BINS; i ++){
                    array[i] = 0;
                }
            }

            numberLocation = value / binSize;
            array[numberLocation] += 1;

            }
            
        }

        for (int i = 0; i < NUMBER_OF_BINS; i++) {

            int first = i * binSize;
                int last = (i + 1) * binSize -1;

                printf("[%2d:%2d] ", first, last);

                for (int j = 0; j <array[i]; j++){
                    printf("*");
                }

                printf("\n");
    }
    
    return 0;
}




