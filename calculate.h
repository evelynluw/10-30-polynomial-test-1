#ifndef CALCULATE_H
#define CALCULATE_H

#include "polynomial.h"
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
    void run(int argc, char *argv[]);

    //TESTING
    void test();

private:
    //VARIABLES
    vector<polynomial> exps = vector<polynomial>(26, polynomial("0")); //TESTED, init vector
    const string commandArr[6] = {"LET", "EVAL", "PRINT", "LOAD", "SAVE", "NEWTON"}; //TESTED, init array

    //MAIN FUNCTIONS
    void prompt(); //TESTED
    string getCommand(istream& in); //TESTED
    void execCommand(string command);
    void let(char funcName, string exp);
    void eval(char funcName, fraction value);
    void print(char funcName);
    void load(string& filename);
    void save(string& filename);
    void algebra(string algebraExp); //TESTED
    void execute(string filename);
    void record(string filename);
    void newton(char funcName, fraction initGuess);

    //ADDITIONAL FUNCTIONS
    string toUpper(string str); //TESTED
    string delSpace(string str); //TESTED
    int index(char funcName);   //TESTED, return 0 for a, 1 for b, etc
    void saveStringToFile(string filename, string line, bool append = false);
    void askString(string prompt, string& theString);



};

#endif // CALCULATE_H
