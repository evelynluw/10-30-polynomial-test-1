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
    temp.combineTerms();
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
    polynomial _y(y);
    for(unsigned int i = 0; i < _y.poly.size(); ++i) {
        _y.poly[i].setTerm(fraction(0)-_y.poly[i].getCoeff(),
                           _y.poly[i].getPower(),
                           _y.poly[i].getVar());
    }
    polynomial temp = x + _y;
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
            if(other[i].getCoeff()<0) {
                out<<" - "<<term(fraction(0) - other[i].getCoeff(),
                                 other[i].getPower(),
                                 other[i].getVar());
            }
            else
                out<<" + "<<other[i];
        }
        if(i==0)
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
    p.poly.clear();
    term _term;
    std::string line;
    std::getline(in,line);
//    p = polynomial(line)
    size_t pos=0, prev = 1;
    while((pos = line.find(' ')) != std::string::npos) {
        line.erase(pos,1);
    }
    line+="+";
    while((pos = line.find_first_of("+-",prev)) != std::string::npos) {
        if(line[pos-1]=='^')
            prev++;
        else {
            prev = 1;
            std::string sterm = line.substr(0, pos);
    //        std::cout<<sterm<<std::endl;
            std::stringstream ssterm;
            ssterm<<sterm;
            ssterm>>_term;
            p.poly.push_back(_term);
            line.erase(0, pos);
            if(line.length()==1)
                line.erase(0,1);
        }
    }
    p.sort();
    p.combineTerms();
    return in;
}
