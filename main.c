#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "util.h"

int main()
{
    bignum *num;
    bignum *num2;
    char *input;
    char *input2;

    printf("Enter a number : ");
    input = secureInput();

    if ((num = BigNum(input)) == NULL){
        exit(1);
    }

    printf("Enter a number : ");
    input2 = secureInput();

    if ((num2 = BigNum(input2)) == NULL){
        exit(1);
    }

    printNum(num);
    printf("\n+\n");
    printNum(num2);
    printf("\n=\n");
    printNum(addBigNum(num, num2));
    

}