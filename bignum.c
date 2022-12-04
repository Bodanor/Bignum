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
    bignum *bigger_array;
    bignum *smaller_array;
    int report = 0;
    int res_size = 0;
    int i, j;
    
    if (src->array_size >= src2->array_size){
        bigger_array = src;
        smaller_array = src2;
    }
    else{
        bigger_array = src2;
        smaller_array = src;
    }
    
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
        res->array[i] = ((bigger_array->array[i] + smaller_array->array[j]) + report) % 10;
        report = (bigger_array->array[i] + smaller_array->array[j] + report) / 10;
        res_size++;
        j--;
        i--;

    }

    while (i >= 0){
        res->array[i] = bigger_array->array[i] + report;
        i--;
        res_size++;
    }

    res->array_size = res_size;

    return res;

}

char *BigNumToStr(bignum*src)
{
    char *tmp = (char*)malloc(sizeof(char)*src->array_size + 1);
    int i;

    if (tmp == NULL){
        fprintf(stderr, "Malloc error !\n");
        return NULL;
    }

    i = 0;

    while (i < src->array_size){
        tmp[i] = src->array[i] + '0';
        i++;
    }

    tmp[i] = '\0';
    return tmp;



}