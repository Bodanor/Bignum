#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "util.h"

#include "seatest.h"

void test_add(void)
{
    bignum *num1;
    bignum *num2;
    bignum *res;

    num1 = BigNum("12");
    num2 = BigNum("12");

    res = addBigNum(num1, num2);
    assert_string_equal("24", BigNumToStr(res));
}
void test_addBigger(void)
{
    bignum *num1;
    bignum *num2;
    bignum *res;

    num1 = BigNum("12378187238971289739817238971289738917289371289371892738917289371892738912");
    num2 = BigNum("12391278309812903890128390128940819048903128490832904890238490832908490384");

    res = addBigNum(num1, num2);
    assert_string_equal("24769465548784193629945629100230557966192499780204797629155780204801229296", BigNumToStr(res));
}
void test_firstLower(void)
{
    bignum *num1;
    bignum *num2;
    bignum *res;

    num1 = BigNum("317828903712893718927389127"); 
    num2 = BigNum("7318927398172893712897389127389127389712893712893789127389127389712893721");

    res = addBigNum(num1, num2);
    assert_string_equal("7318927398172893712897389127389127389712893713211618031102021108640282848", BigNumToStr(res));

}
void test_fixture_add(void)
{
    test_fixture_start();      
    run_test(test_add);   
    run_test(test_addBigger);   
    run_test(test_firstLower);
    test_fixture_end();    
}
void all_tests(void)
{
    test_fixture_add();
}


int main()
{
   return run_tests(all_tests);
    

}