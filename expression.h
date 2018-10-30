#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "polynomial.h"
#include <iostream>
#include <vector>

using namespace std;

class expression
{
public:
    expression();
    expression(string _command);
    void clearLibrary();
    ~expression;
    void exec();

private:
    vector<polynomial> library;
    string command;
    void let();
    void eval();
    void print();

};

#endif // EXPRESSION_H
