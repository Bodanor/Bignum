#include "bignum.h"


struct BIGNUM_t
{
    long int array_size;
    int *array;

};

void printNum(bignum *ptr)
{
    int *temp = ptr->array;

    while (temp - ptr->array < ptr->array_size)
        printf("%d", *temp++);

}

bignum *BigNum(const char *ptr)
{
    bignum * tmp = (bignum*)malloc(sizeof(bignum));
    int *array_tmp;

    if (tmp == NULL)
        return NULL;
    
    tmp->array_size = strlen(ptr);

    tmp->array = (int*)malloc(sizeof(int) *tmp->array_size);
    if (tmp->array == NULL)
        return NULL;
    
    array_tmp = tmp->array;
    while (*ptr != '\0')
        *array_tmp++ = *ptr++ - '0';
    
    return tmp;

};

void destroyBigNum(bignum *ptr)
{
    free(ptr->array);
    free(ptr);

}