#include "expression.h"

expression firstDerivative(const expression &other)
{
    expression temp;
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

expression nthDerivative(const expression &other, const int n) {
    expression temp(other);
    for(int i = 0; i < n; ++i) {
        temp = firstDerivative(temp);
    }
    return temp;
}

expression operator+(const expression &x, const expression &y)
{
    expression temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        temp.poly.push_back(x[i]);
    for(unsigned int i = 0; i < y.poly.size(); ++i)
        temp.poly.push_back(y[i]);
    temp.sort();
//    std::cout << "term combining .. 1" << std::endl;
    temp.combineTerms();
    return temp;

}


expression operator-(const expression &x, const expression &y)
{
    expression temp = x + y;
    return temp;
}


expression operator*(const expression &x, const expression &y)
{
    expression temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        for(unsigned int j = 0; j < y.poly.size(); ++j)
            temp.poly.push_back(x[i] * y[j]);
    temp.sort();
    temp.combineTerms();
    return temp;
}


expression operator/(const expression &x, const expression &y)
{
    //do this with synthetic division.... hint...
    //Also, does expression need to be changed to support division??
    return x;
}


std::ostream& operator<<(std::ostream& out, const expression &other) //TESTED
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


std::istream& operator>>(std::istream& in, expression &p)
{
    //still have problems with line endings
    //plan to take the line as a string
    //and parse the string as a couple of
    //terms...
    term _term;
    std::string line;
    std::getline(in,line);
//    p = expression(line)
    size_t pos=0;
    while((pos = line.find(' ')) != std::string::npos) {
        line.erase(pos,1);
    }
    line+="+";
    while((pos = line.find_first_of("+-",1)) != std::string::npos) {
        std::string sterm = line.substr(0, pos);
        std::cout<<sterm<<std::endl;
        std::stringstream ssterm;
        ssterm<<sterm;
        ssterm>>_term;
        p.poly.push_back(_term);
        line.erase(0, pos);
        if(line.length()==1)
            line.erase(0,1);
    }
    p.sort();
    p.combineTerms();
    return in;
}
