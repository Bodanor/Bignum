#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"

int main()
{
    char buffer[50];
    int c;
    unsigned int i = 0;
    bignum *num;

    printf("Enter a number : ");
    while ((c = getchar()) != '\n' && i < sizeof(buffer) -1)
        buffer[i++] = c;

    buffer[i] = '\0';
    if ((num = BigNum(buffer)) == NULL){
        fprintf(stderr, "BigNum error !\n");
        exit(1);
    }
    printNum(num);
    destroyBigNum(num);

}