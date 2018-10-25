#include "fraction.h"
//#include <typeinfo>

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
         out<<"/"<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
    char junk;
    int part1, part2;
    if(in>>part1)
    {
        if(in.peek() == '/') {
            in>>junk>>part2;
            frac.num = part1;
            frac.denom = part2;
        }
        if(in.peek() == '.')
        {
            in>>junk>>part2;
            double doublePart = frac.makeDouble(part1, part2);
            frac.DecimaltoFrac(doublePart, frac.num, frac.denom);
        }
        else{
            frac.num = part1;
            frac.denom = 1;
        }
    }
    else
        std::cout<<"Hit End of File"<<std::endl;
    return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom + y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom - y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.num,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    result.setValue(num,denom);
    return result;
}

bool operator==(const fraction &x,const fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}
