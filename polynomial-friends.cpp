#include "polynomial.h"

polynomial firstDerivative(const polynomial &other)
{
    polynomial temp;
    term newTerm;
    for(unsigned int i = 0; i < other.poly.size(); ++i)
    {
        newTerm.setTerm(
            other[i].getCoeff()*other[i].getPower() ,
            other[i].getPower()-1
            );
        temp.poly.push_back(newTerm);
    }
    return temp;
}

polynomial nthDerivative(const polynomial &other, const int n) {
    polynomial temp(other);
    for(int i = 0; i < n; ++i) {
        temp = firstDerivative(temp);
    }
    return temp;
}

polynomial operator+(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        temp.poly.push_back(x[i]);
    for(unsigned int i = 0; i < y.poly.size(); ++i)
        temp.poly.push_back(y[i]);
    temp.sort();
//    std::cout << "term combining .. 1" << std::endl;
    temp.combineTerms();
    return temp;

}


polynomial operator-(const polynomial &x, const polynomial &y)
{
    polynomial temp = x + y;
    return temp;
}


polynomial operator*(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        for(unsigned int j = 0; j < y.poly.size(); ++j)
            temp.poly.push_back(x[i] * y[j]);
    temp.sort();
    temp.combineTerms();
    return temp;
}


polynomial operator/(const polynomial &x, const polynomial &y)
{
    //do this with synthetic division.... hint...
    //Also, does polynomial need to be changed to support division??
    return x;
}


std::ostream& operator<<(std::ostream& out, const polynomial &other) //TESTED
{
    for(unsigned int i = 0; i < other.poly.size(); ++i){
        if(i!=0){
            if(other[i].getCoeff()<0)
                out<<'-';
            else
                out<<'+';
        }
        out<<other[i];
    }
    return out;
}


std::istream& operator>>(std::istream& in, polynomial &p)
{
    //still have problems with line endings
    //plan to take the line as a string
    //and parse the string as a couple of
    //terms...
    term temp;
//    p = polynomial(line)
    while(in.peek()!='\n'){
        //GETLINE
        //PARSE FOR EMPTY SPACES
        //
        in>>temp;
        p.poly.push_back(temp);
    }

    p.sort();
    p.combineTerms();
    return in;
}
