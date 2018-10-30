#include "expression.h"

//PUBLIC
//CTORS

expression::expression()
{

}

expression::~expression()
{
    poly.clear();
}

expression::expression(const expression &other)
{
    copy(other);
}

expression::expression(const term &other)
{
    poly.push_back(other);
}

expression::expression(std::string expString) { //TESTED
    setExp(expString);
}

//PUBLIC FUNCTIONS

void expression::setExp(std::string expString) { //TESTED
    std::stringstream ss;
    ss<<expString;
    ss>>*this;
}

fraction expression::evaluate(const fraction &other) { //TESTED
    fraction temp(0);
    for(std::vector<term>::iterator it = poly.begin(); it != poly.end(); ++it) {
        temp += it->evaluate(other);
    }
    return temp;
}

void expression::addterm(const term &term_arg) { //TESTED
    poly.push_back(term_arg);
}

std::string expression::polyString() {
    std::stringstream ss;
    std::string temp;
    ss<<*this;
    std::getline(ss, temp);
    return temp;
}


//OPERATORS
expression& expression::operator=(const expression &other)
{
    if(this != &other)
    {
        poly.clear();
        copy(other);
    }
    return *this;
}

expression& expression::operator+=(const expression &other)
{
    expression ans = *this + other;
    *this = ans;
    return *this;
}

expression& expression::operator-=(const expression &other)
{
    expression ans = *this - other;
    *this = ans;
    return *this;
}

expression& expression::operator*=(const expression &other)
{
    expression ans = *this * other;
    *this = ans;
    return *this;
}

expression& expression::operator/=(const expression &other)
{
    expression ans = *this / other;
    *this = ans;
    return *this;
}

fraction expression::operator()(const fraction &other) //TESTED
{
//    fraction result;
//    for(unsigned int i = 0; i < poly.size(); ++i)
//        result += poly[i](other);
    return this->evaluate(other);
}


term expression::operator[](unsigned int index) const
{
    return poly[index];
}

/*
 * Suppose that there is a expression named f.
 * then the operator below will allow:
 * f[3] = term(3,2);
 * Meaning, we can index the expression like and array and
 * assign new values to each term.
 */
term& expression::operator[](unsigned int index)
{
    return poly[index];
}

void expression::copy(const expression &other)
{
    for(unsigned int i = 0; i < other.poly.size(); ++i)
        poly.push_back(other[i]);
}

void expression::sort()
{
    term temp;
    for(unsigned int i = 0; i < poly.size(); ++i)
        for(unsigned int j = 0; j < poly.size(); ++j)
            if(poly[i] > poly[j])
            {
                temp = poly[i];
                poly[i] = poly[j];
                poly[j] = temp;
            }
}

void expression::combineTerms()
{
    for(unsigned int i = 0; i < poly.size()-1; ++i)
        if(poly[i].getPower() == poly[i+1].getPower())
        {
//            std::cout << "term combining .. 2" << std::endl;
            poly[i].setTerm(poly[i].getCoeff() + poly[i + 1].getCoeff(),
                            poly[i].getPower());
            poly.erase(poly.begin() + i + 1);
        }
}
/*
 *   *(x + 2) is the same as x[2] in an array!!!
 *
 *    for(vector<term>::iterator i = poly.begin(); i != poly.end(); ++i
 *           cout<<*i<<endl;
 *
 *    for(vector<term>::iterator i = poly.rbegin(); i != poly.rend(); --i
 *           cout<<*i<<endl;
 */
