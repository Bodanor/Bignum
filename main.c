#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "util.h"

int main()
{
    bignum *num;
    bignum *num2;
    bignum *res;

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
    res = addBigNum(num, num2);
    printNum(res);

    free(input);
    free(input2);
    destroyBigNum(num);
    destroyBigNum(num2);
    destroyBigNum(res);
    

}