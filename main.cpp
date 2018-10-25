#include <iostream>
#include "polynomial.h"

using namespace std;

void test_eval();

int main()
{
    test_eval();
    return 0;
}

void test_eval() {
    fraction frac1(5,2), frac2(1,3);
    term term1(frac1, frac2);
    polynomial poly1(term1);
    cout<<term1(8)<<endl;
}
