#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Lara Dalberg"
#define YEAR "2022"

void Dec2RadI(int decValue, int radValue){
    if(decValue == 0){                                  // when the decimal value is zero, radix-i value will be 0
        printf("\nthe radix-%d value is 0", radValue);
    }

    else{
        int bits = ceil(log2(decValue)/log2(radValue));      // find number of bits
        float check_bits = log2(decValue)/log2(radValue);    // in the case where the bits calculation is as exact integer, add 1
        if(check_bits == bits){
            bits += 1;
        }
    
        char convert[bits];                               // create empty string array for the converted number to be stored in
        char multipliers[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};

        for (int i = bits; i > 0; i--){
            int multValue = decValue%radValue;        // find multiplier value by getting remainder of decimal/radix
        
            convert[i] = multipliers[multValue];     // fetch appropriate multiplier char value from the multipliers array, append this value to the string array
        
            decValue = decValue/radValue;           // find the remaining decimal number by getting the integer result of decimal/radix, set this as the new decimal
        }

        printf("\nThe radix-%d value is ", radValue);

        for (int j = 1; j <= bits; j++){        // sequentially print the elements in the string array to display the final radix-i value
            printf("%c", convert[j]);
        }
    }
}


int main(){
    /* printing title block */
    
    printf("*****************************\n %s\n Written by: %s\n Date: %s\n*****************************", TITLE, AUTHOR, YEAR);
    
    int dec, rad;

    while(!0){
        /* fetching user inputs */
        
        printf("\nEnter a decimal number: ");
        scanf("%d", &dec);
        if (dec < 0){
            break;          // terminate the loop using break statement
        }
        else {
            printf("The decimal number you have entered is %d", dec);
        }
        
        printf("\nEnter a radix for converter between 2 and 16: ");
        scanf("%d", &rad);
        if (rad < 0){ 
            break;         // terminate the loop using break statement
        }
        else{
            printf("the radix you have entered is %d", rad);
        }
        
        /* CALCULATIONS */

        float logValue = log2(dec);
        printf("\nThe log2 of the number is %f", logValue);

        int div = dec/rad;
        printf("\nThe integer result of the number divided by %d is %d", rad, div);

        int rem = dec%rad;
        printf("\nThe remainder is %d", rem);

        Dec2RadI(dec, rad);         // calling function to calculate the radix-i value

    }
    
    printf("EXIT");
    
    return 0;
}