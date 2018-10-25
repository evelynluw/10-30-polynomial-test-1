#include "fraction.h"

//PUBLIC
//CTORS

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n, int d)
{
   setValue(n,d);
}


fraction::~fraction()
{
    num = denom = 0;
}
/*
 * The copy constructor is fired whenever
 * 1. You pass by value
 * 2. You use a return statement that
 *    does not got back to a reference
 */
fraction::fraction(const fraction &frac)
{
    num = frac.num;
    denom = frac.denom;
}

fraction::fraction(const double &other)
{
    DecimaltoFrac(other, num, denom);
    reduce();
}

//OPERATOR FUNCTIONS (NOT FRIENDS)

/*
 * The assignment operator needs to be
 * returned by reference so that you can
 * "chain" operators.
 * e.g.
 * x = y = z;
 */
fraction& fraction::operator=(const fraction &frac)
{
    if(this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}

//PUBLIC FUNCTIONS

int fraction::getNum() //accessor function for numerator
{
    return num;
}

int fraction::getDenom()//accessor function for denominator
{
    return denom;
}

void fraction::setValue(int n, int d) //mutator function
{
    num = n;
    denom = d;
    reduce();
}

void fraction::display()
{
    std::cout<<" "<<num;
    if(denom != 1)
       std::cout<<"/"<<denom<<" ";
}


void fraction::getInput()
{
    char junk;
    std::cin>>num>>junk>>denom;
    reduce();
}


void fraction::reduce()
{
    bool neg = num < 0 || denom < 0,
         both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both) //Asking is both == false
        if(neg)
            num *= -1;
}

fraction fraction::reduceFraction() {
    fraction temp(num, denom);
    temp.reduce();
    return temp;
}

double fraction::evaluate() //TESTED
{
     return num*1./denom;
}

double fraction::pow(fraction base, fraction power) { //TESTED
    return std::pow(base.evaluate(), power.evaluate());
}

bool fraction::isExactlyTheSame(fraction other) {
    return (num == other.num && denom == other.denom);
}

//PRIVATE
//PRIVATE UTILITY FUNCTIONS

int fraction::gcd(int p, int q)
{
   return !q ? p : gcd(q, p%q);  //!q is the same as asking q == 0;
}

/*
 *  Remainder Theorem
 *
 *  P = nQ + R;
 *
 * 36 = (1)(24) + 12  Question, is 12 == 0?
 * 24 = (2)(12) + 0   If no, move Q into P, and R into Q and continue
 *                    until R == 0;
 * If R== 0, that means Q is the GCD of the original numbers provided
 *
 */


bool fraction::allDecimalsTheSame(const std::string &fracPart)
{
    if(fracPart.size()<3)
        return false;
    bool yes = true;
    for(int i = 1; yes && i < fracPart.size(); ++i)
        yes = (fracPart[0] == fracPart[i]);
    return yes;
}

int fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return std::stoi(result) - (int)same * 1;
    //stoi: convert string to integer
}

void fraction::DecimaltoFrac(const double &other, int &num_arg, int &denom_arg) {
    //TESTED, COULD IMPROVE
    std::string wholePart, fractionPart;
    std::stringstream ss;
    ss<<other;
    getline(ss,wholePart,'.'); //treat '.' as a delimination char
    getline(ss,fractionPart, '\n');
    int numDigits = fractionPart.size();
    denom_arg = makeDenom(numDigits, allDecimalsTheSame(fractionPart));
    if(fractionPart.empty())
        num_arg = denom_arg * std::stoi(wholePart);
    else
        num_arg = denom_arg * std::stoi(wholePart) + std::stoi(fractionPart);
}

double fraction::makeDouble(int intPart, int deciPart) {
    std::stringstream ssdouble;
    ssdouble<<intPart<<'.'<<deciPart;
    double temp;
    ssdouble>>temp;
    return temp;
}


