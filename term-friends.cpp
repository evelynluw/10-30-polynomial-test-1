#include "term.h"

//term operator+(const term &x, const term &y)
//{
//    //disabled cuz polynoimials can add
//}

//term operator-(const term &x, const term &y)
//{
//    //    //disabled cuz polynoimials can add/minus
//}

term operator*(const term &x, const term &y)
{
    term temp(x.coeff*y.coeff, x.power + y.power);
    return temp;
}

term operator/(const term &x, const term &y)
{
    term temp(x.coeff/y.coeff, x.power - y.power);
    return temp;
}


bool operator==(const term &x, const term &y)
{
    return x.power == y.power && x.coeff == y.coeff;
}


bool operator!=(const term &x, const term &y)
{
    return x.power != y.power || x.coeff != y.coeff;
}

bool operator%=(const term &x, const term &y)
{
    return x.power == y.power;
}


bool operator>=(const term &x, const term &y)
{
    return !(x < y);
}


bool operator<=(const term &x, const term &y)
{
    return !(x > y);
}


bool operator>(const term &x, const term &y)
{
    if(x.power == y.power)
        return x.coeff > y.coeff;
    else
        return x.power > y.power;
}


bool operator<(const term &x, const term &y)
{
    if(x.power == y.power)
        return x.coeff < y.coeff;
    else
        return x.power < y.power;
}

std::ostream& operator<<(std::ostream& out, const term& t)
{
    out<<t.coeff<<t.var<<'^'<<t.power;
    return out;
}


std::istream& operator>>(std::istream& in, const term& t)
{
    /* the idea here is to look for ^
     * and using string functions to find the
     * coeff, var, and power.
     * stringstream is going to be used very carefully...
     */
    char junk;
    in>>t.coeff>>t.var>>junk>>t.power;
    return in;
}

















