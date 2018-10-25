#include "term.h"

term::term(char v)
{
    coeff = power = fraction(0);
    var = v;
}

term::term(const fraction &c, const fraction& p, char v)
{
    coeff = c;
    power = p;
    var = v;
}

term::~term()
{
    coeff = power = 0;
    var = '\0';
}

term::term(const term& other)
{
    copy(other);
}

term& term::operator=(const term& other)
{
    if(this != &other)
        copy(other);
    return *this;
}


fraction term::getPower()
{
    return power;
}

fraction term::getCoeff()
{
    return coeff;
}

char term::getVar() {
    return var;
}

void term::setTerm(const fraction &c, const fraction p)
{
    coeff = c;
    power = p;
}


term& term::operator*=(const term& other)
{
    return (*this = *this * other);
}

term& term::operator/=(const term& other)
{
    return (*this = *this / other);
}

double term::evaluate(const fraction& other) //TESTED
{
   double temp = coeff.evaluate()*power.pow(other, power);
   return temp;
}

fraction term::operator()(const fraction& other)
{
   return evaluate(other);
}


void term::copy(const term &other)
{
//    std::cout<<"COPY FIRED"<<std::endl;
    coeff = other.coeff;
    power = other.power;
    var = other.var;
}
