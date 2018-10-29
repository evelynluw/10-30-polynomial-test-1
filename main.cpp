#include <iostream>
#include "polynomial.h"
#include <string>

using namespace std;

void test_eval();
void test_cin();

int main()
{
    test_cin();
    return 0;
}

void test_eval() {  //tested
    fraction frac1(5,2), frac2(1,3);
    term term1(frac1, frac2);
    polynomial poly1(term1);
    cout<<term1(8)<<endl;
}

void test_cin() {
    polynomial poly1, poly2;
    cout<<"poly1: ";
    cin>>poly1;
    cout<<poly1;

//    //TESTED:
//    term term1, term2;
//    cout<<"term1: "<<endl;
//    cin>>term1;
//    cout<<term1<<endl;
//    cin>>term2;
//    cout<<term2<<endl;

//    //TESTED:
//    fraction frac1, frac2, frac3;
//    cout<<"frac1: "<<endl;
//    cin>>frac1;
//    cout<<frac1<<endl;
//    cout<<"frac2: "<<endl;
//    cin>>frac2;
//    cout<<frac2<<endl;
//    cout<<"frac3: "<<endl;
//    cin>>frac3;
//    cout<<frac3<<endl;
}







