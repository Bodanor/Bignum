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
    bignum *bigger_array = src->array_size > src2->array_size ? src : src2;
    bignum *smaller_array = src->array_size < src2->array_size ? src : src2;
    int report = 0;
    int res_size = 0;
    int i, j;
    

    bignum *res = (bignum*)malloc(sizeof(bignum));
    if (res == NULL){
        fprintf(stderr, "Memory alloc error !\n");
        return NULL;
    }

    res->array = (int*)malloc(sizeof(int)*bigger_array->array_size + 1);
    if (res->array == NULL){
        fprintf(stderr, "Memory alloc error !\n");
        return NULL;

    }

    i = bigger_array->array_size - 1, j = smaller_array->array_size - 1;

    while (j >= 0){
        res->array[i] = (bigger_array->array[i] + smaller_array->array[j]) % 10 + report;
        report = (bigger_array->array[i] + smaller_array->array[j]) / 10;
        res_size++;
        j--;
        i--;

    }

    while (i >= 0){
        res->array[i] = bigger_array->array[i];
        i--;
        res_size++;
    }
    
    res->array_size = res_size;

    return res;

}