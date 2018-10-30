#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "term.h"

class polynomial  //this is pavan testing out git
{
    public:
        //CTORS
        polynomial();
        ~polynomial();
        polynomial(const term &other);
        polynomial(const polynomial &other);
        polynomial(std::string expString); //TESTED

        //Public Functions
        void setExp(std::string expString); //TESTED
        fraction evaluate(const fraction &other); //TESTED
        double evaluate(const double value);
        void addterm(const term &term_arg); //TESTED
        std::string polyString();

        //Operators
        polynomial& operator=(const polynomial &other);
        polynomial& operator+=(const polynomial &other);
        polynomial& operator-=(const polynomial &other);
        polynomial& operator*=(const polynomial &other);
        polynomial& operator/=(const polynomial &other);
        fraction operator()(const fraction &other);
        term operator[](unsigned int index) const;
        term& operator[](unsigned int index);

        friend
        polynomial firstDerivative(const polynomial &other);

        friend
        polynomial nthDerivative(const polynomial &other, const int n);

        friend
        polynomial operator+(const polynomial &x, const polynomial &y);

        friend
        polynomial operator-(const polynomial &x, const polynomial &y);

        friend
        polynomial operator*(const polynomial &x, const polynomial &y);

        friend
        polynomial operator/(const polynomial &x, const polynomial &y);

        friend
        std::ostream& operator<<(std::ostream& out, const polynomial &p);

        friend
        std::istream& operator>>(std::istream& in,  polynomial &p);

     private:
        std::vector<term> poly;

        void copy(const polynomial &other);
        void sort();
        void combineTerms();
};

#endif
