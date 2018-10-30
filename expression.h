#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "term.h"

class expression  //this is pavan testing out git
{
    public:
        //CTORS
        expression();
        ~expression();
        expression(const term &other);
        expression(const expression &other);
        expression(std::string expString); //TESTED

        //Public Functions
        void setExp(std::string expString); //TESTED
        fraction evaluate(const fraction &other); //TESTED
        void addterm(const term &term_arg); //TESTED
        std::string polyString();

        //Operators
        expression& operator=(const expression &other);
        expression& operator+=(const expression &other);
        expression& operator-=(const expression &other);
        expression& operator*=(const expression &other);
        expression& operator/=(const expression &other);
        fraction operator()(const fraction &other);
        term operator[](unsigned int index) const;
        term& operator[](unsigned int index);

        friend
        expression firstDerivative(const expression &other);

        friend
        expression nthDerivative(const expression &other, const int n);

        friend
        expression operator+(const expression &x, const expression &y);

        friend
        expression operator-(const expression &x, const expression &y);

        friend
        expression operator*(const expression &x, const expression &y);

        friend
        expression operator/(const expression &x, const expression &y);

        friend
        std::ostream& operator<<(std::ostream& out, const expression &p);

        friend
        std::istream& operator>>(std::istream& in,  expression &p);

     private:
        std::vector<term> poly;

        void copy(const expression &other);
        void sort();
        void combineTerms();
};

#endif
