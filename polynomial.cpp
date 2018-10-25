#include "polynomial.h"

//PUBLIC
//CTORS

polynomial::polynomial()
{

}

polynomial::~polynomial()
{
    poly.clear();
}

polynomial::polynomial(const polynomial &other)
{
    copy(other);
}

polynomial::polynomial(const term &other)
{
    poly.push_back(other);
}

//PUBLIC FUNCTIONS
fraction polynomial::evaluate(const fraction &other) { //TESTED
    fraction temp(0);
    for(std::vector<term>::iterator it = poly.begin(); it != poly.end(); ++it) {
        temp += it->evaluate(other);
    }
    return temp;
}

void polynomial::addterm(const term &term_arg) { //TESTED
    poly.push_back(term_arg);
}

std::string polynomial::polyString() {
    std::stringstream ss;
    std::string temp;
    ss<<*this;
    std::getline(ss, temp);
    return temp;
}


//OPERATORS
polynomial& polynomial::operator=(const polynomial &other)
{
    if(this != &other)
    {
        poly.clear();
        copy(other);
    }
    return *this;
}

polynomial& polynomial::operator+=(const polynomial &other)
{
    polynomial ans = *this + other;
    *this = ans;
    return *this;
}

polynomial& polynomial::operator-=(const polynomial &other)
{
    polynomial ans = *this - other;
    *this = ans;
    return *this;
}

polynomial& polynomial::operator*=(const polynomial &other)
{
    polynomial ans = *this * other;
    *this = ans;
    return *this;
}

polynomial& polynomial::operator/=(const polynomial &other)
{
    polynomial ans = *this / other;
    *this = ans;
    return *this;
}

fraction polynomial::operator()(const fraction &other) //TESTED
{
//    fraction result;
//    for(unsigned int i = 0; i < poly.size(); ++i)
//        result += poly[i](other);
    return this->evaluate(other);
}


term polynomial::operator[](unsigned int index) const
{
    return poly[index];
}

/*
 * Suppose that there is a polynomial named f.
 * then the operator below will allow:
 * f[3] = term(3,2);
 * Meaning, we can index the polynomial like and array and
 * assign new values to each term.
 */
term& polynomial::operator[](unsigned int index)
{
    return poly[index];
}

void polynomial::copy(const polynomial &other)
{
    for(unsigned int i = 0; i < other.poly.size(); ++i)
        poly.push_back(other[i]);
}

void polynomial::sort()
{
    term temp;
    for(unsigned int i = 0; i < poly.size(); ++i)
        for(unsigned int j = 0; j < poly.size(); ++j)
            if(poly[i] < poly[j])
            {
                temp = poly[i];
                poly[i] = poly[j];
                poly[j] = temp;
            }
}

void polynomial::combineTerms()
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
