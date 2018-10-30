#ifndef CALCULATE_H
#define CALCULATE_H

#include "expression.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class calculate
{
public:
    //constructor
    calculate();
    //UI for the program
    void run();

    //TESTING
    void test();

private:
    //VARIABLES
    vector<expression> exps = vector<expression>(26); //TESTED, init vector
    const string commandArr[5] = {"LET", "EVAL", "PRINT", "LOAD", "SAVE"}; //TESTED, init array

    //MAIN FUNCTIONS
    void prompt(); //TESTED
    string getCommand(istream& in); //TESTED
    void execCommand(string command);
    void let(char funcName, string exp);
    void eval(char funcName, fraction value);
    void print(char funcName);
    void load(string filename);
    void save(string filename);
    void algebra(string algebraExp);

    //ADDITIONAL FUNCTIONS
    string toUpper(string str); //TESTED
    string delSpace(string str); //TESTED
    int index(char funcName);   //TESTED, return 0 for a, 1 for b, etc



};

#endif // CALCULATE_H
