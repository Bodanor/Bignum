#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "util.h"

int main()
{
    bignum *num;
    char *input;

    printf("Enter a number : ");
    input = secureInput();

    if ((num = BigNum(input)) == NULL){
        fprintf(stderr, "BigNum error !\n");
        exit(1);
    }
    printNum(num);
    destroyBigNum(num);
    free(input);

}