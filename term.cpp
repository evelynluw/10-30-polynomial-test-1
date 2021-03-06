#include "term.h"

term::term(char v)
{
    coeff = power = fraction(0);
    var = v;
}

term::term(const fraction &c, const fraction& p, char v)
{
    setTerm(c, p, v);
}

term::term(std::string termString) {
    setTerm(termString);
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

void term::setTerm(const fraction &c, const fraction p, char v)
{
    coeff = c;
    power = p;
    var = v;
}

void term::setTerm(std::string termString) { //TESTED
    std::stringstream ss;
    ss<<termString;
    ss>>*this;
}

term& term::operator*=(const term& other)
{
    return (*this = *this * other);
}

term& term::operator/=(const term& other)
{
    return (*this = *this / other);
}

fraction term::evaluate(const fraction& other) //TESTED
{
//   double temp = coeff.evaluate()*power.pow(other, power);
    fraction temp = coeff*(other^power);
    return temp;
}

double term::evaluate(const double value) {
    double temp = coeff.evaluate()*pow(value, power.evaluate());
    return temp;
}

fraction term::operator()(const fraction& other) //TESTED
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
