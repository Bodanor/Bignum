#ifndef __BIGNUM_H__
#define __BIGNUM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_BUFF 10
#define STR_BUFF 10

typedef struct BIGNUM_t bignum;

bignum *BigNum(const char *);
void destroyBigNum(bignum *);
void printNum(bignum *);
bignum *addBigNum(bignum *, bignum*);
char *BigNumToStr(bignum*);
#endif