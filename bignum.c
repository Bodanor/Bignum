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
    if (tmp->array == NULL){
        fprintf(stderr, "Memory alloc error !\n");
        return NULL;
    }
    
    array_tmp = tmp->array;
    while (*ptr != '\0'){
        if (isdigit(*ptr))
            *array_tmp++ = *ptr++ - '0';
        else{
            fprintf(stderr, "Non digit char found !\n");
            return NULL;
        }
    }
    
    return tmp;

};

void destroyBigNum(bignum *ptr)
{
    free(ptr->array);
    free(ptr);

}

bignum *addBigNum(bignum *src, bignum*src2)
{
    int bigger_size = src->array_size > src2->array_size ? src->array_size : src2->array_size;
    int report = 0;
    int res_size = 0;

    bignum *res = (bignum*)malloc(sizeof(bignum));
    if (res == NULL){
        fprintf(stderr, "Memory alloc error !\n");
        return NULL;
    }

    res->array = (int*)malloc(sizeof(int)*10);
    if (res->array == NULL){
        fprintf(stderr, "Memory alloc error !\n");
        return NULL;

    }
    while (bigger_size >= 0){

        res->array[bigger_size] = (src->array[bigger_size] + src2->array[bigger_size]) % 10 + report;
        report = (src->array[bigger_size] + src2->array[bigger_size]) / 10;
        bigger_size--;
        res_size++;
    }

    res->array_size = res_size - 1;


    return res;

}