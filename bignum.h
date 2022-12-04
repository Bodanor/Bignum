#ifndef __BIGNUM_H__
#define __BIGNUM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct BIGNUM_t bignum;

bignum *BigNum(const char *);
void destroyBigNum(bignum *);
void printNum(bignum *);
bignum *addBigNum(bignum *, bignum*);
#endif