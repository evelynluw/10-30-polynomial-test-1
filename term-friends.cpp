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

std::ostream& operator<<(std::ostream& out, const term& t) //TESTED
{
    if(t.coeff != 1)
        out<<t.coeff;
    out<<t.var;
    if(t.power != 1)
        out<<'^'<<t.power;
    return out;
}


std::istream& operator>>(std::istream& in, term& t) //TESTED
{
    /* the idea here is to look for ^
     * and using string functions to find the
     * coeff, var, and power.
     * stringstream is going to be used very carefully...
     */

    //assuming there will only be 3 types of
    //inputs: 3/2x^2, x^5, 5
    fraction coeff(1), power(1);
    char var, junk;
    if(isdigit(in.peek())) { //[2]x^2
        in>>coeff;
    }
    if(isalpha(in.peek())) { //[x]^2
        in>>var;
    }
    if(in.peek()=='^') { //x[^]2
        in>>junk>>power;
    }
    if(in.peek()=='\n') //I guess??
        in.ignore();
    t.setTerm(coeff, power, var);
    return in;
}

















