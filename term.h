#ifndef TERM_H
#define TERM_H
#include <iostream>
#include <fstream>
#include "fraction.h"
#include <cmath>

class term
{
    public:
        term(char v = 'x');
        term(const fraction &c, const fraction& p = 0, char v = 'x');
        ~term();
        term(const term& other);
        term& operator=(const term& other);
        term& operator*=(const term& other);
        term& operator/=(const term& other);
//        term& operator+=(const term& other);
//        term& operator-=(const term& other);
        fraction getPower();
        fraction getCoeff();
        char getVar();
        void setTerm(const fraction &c, const fraction p = 0);
        fraction evaluate(const fraction& other);
        fraction operator()(const fraction& other);
        //y = x(3/4); where y and x are terms

        friend
        term operator*(const term &x, const term &y);

        friend
        term operator/(const term &x, const term &y);

        friend
        bool operator==(const term &x, const term &y);

        friend
        bool operator!=(const term &x, const term &y);

        friend
        bool operator>=(const term &x, const term &y);

        friend
        bool operator<=(const term &x, const term &y);

        friend
        bool operator>(const term &x, const term &y);

        friend
        bool operator<(const term &x, const term &y);

        friend
        bool operator%=(const term &x, const term &y);

        friend
        std::ostream& operator<<(std::ostream& out, const term& t);

        friend
        std::istream& operator>>(std::istream& in, const term& t);

    private:

        fraction coeff, power;
        char var;

        void copy(const term &other);
};

#endif // TERM_H
