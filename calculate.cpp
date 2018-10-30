#include "calculate.h"

//PUBLIC

//..CONSTRUCTOR

calculate::calculate()
{
    //initialization done in class variable declarations
}

//..MAIN PROGRAM

void calculate::run() {

}

//..TESTING
void calculate::test() {
    execCommand("F = G''''");

}

//PRIVATE

//..MAIN FUNCTIONS

void calculate::prompt() { //TESTED
    cout<<"INPUT: "<<endl;
}

string calculate::getCommand(istream& in) { //TESTED: cout<<getCommand(cin)<<endl;
    string temp;
    getline(in, temp);
    return temp;
}

void calculate::execCommand(string command) {
    /* sample argm:
     * LET F = 2X + 4
     * EVAL F(1/4)
     * PRINT F
     * LOAD filename.exp
     * SAVE filename.exp
     * F = G + H
     */
    string noSpaceCommand = delSpace(command),
            upperCommand = toUpper(noSpaceCommand);
    for(unsigned int i = 0; i < 5; ++i) {
        size_t pos=0;
        if((pos = upperCommand.find(commandArr[i])) != string::npos) {
            string exp = noSpaceCommand.substr(pos+commandArr[i].length()) ;
            switch (i) {
            case 0: //LET, exp = "F=2X+4", TESTED
            {
                char funcName = exp[0];
                exp.erase(0,2);
                let(funcName, exp);
                break;
            }
            case 1: //EVAL, exp = "F(1/4)", TESTED
            {
                char funcName = exp[0];
                fraction value(exp.substr(2,exp.length()-1-2));
                eval(funcName, value);
                break;
            }
            case 2: //PRINT, exp = "F", TESTED
            {
                char funcName = exp[0];
                print(funcName);
                break;
            }
            case 3: //LOAD, exp = "FILENAME.EXP", TESTED
            {
                load(exp);
                break;
            }
            case 4: //SAVE, exp = "FILENAME.EXP", TESTED
            {
                save(exp);
                break;
            }
            default:
                break;
            }
            return;
        }
    }

    algebra(noSpaceCommand); //"F=G+H", TESTED
}

void calculate::let(char funcName, string exp) {

}

void calculate::eval(char funcName, fraction value) {

}

void calculate::print(char funcName) {

}

void calculate::load(string filename) {

}

void calculate::save(string filename) {

}

void calculate::algebra(string algebraExp) { //TESTED
    /* sample argm:
     * F=G+H
     * F=G-H
     * F=G*H
     * F=G'
     * F=G'''
     */
    size_t pos;
    if((pos = algebraExp.find_first_of("+-*"))!= string::npos) {
        char fn1 = algebraExp[0], //funcName
                fn2 = algebraExp[2],
                fn3 =  algebraExp[4];
        switch (algebraExp[pos]) {
        case '+': //TESTED
            exps[index(fn1)] = exps[index(fn2)] + exps[index(fn3)];
            break;
        case '-': //TESTED
            exps[index(fn1)] = exps[index(fn2)] - exps[index(fn3)];
            break;
        case '*': //TESTED
            exps[index(fn1)] = exps[index(fn2)] * exps[index(fn3)];
            break;
        default:
            break;
        }
        return;
    }
    if((pos = algebraExp.find('\''))!= string::npos) { //TESTED
        char fn1 = algebraExp[0],
                fn2 = algebraExp[2];
        int derCount = 1;
        while((pos = algebraExp.find('\'', pos+1))!= string::npos)
            derCount++;
        exps[index(fn1)]= nthDerivative(exps[index(fn2)], derCount);
        return;
    }

    //throw error here

}

//..ADDITIONAL FUNCTIONS

string calculate::toUpper(string str) { //TESTED
    string temp;
    for(string::iterator it=str.begin(); it!=str.end(); ++it){
        temp.push_back(toupper(*it));
    }
    return temp;
}

string calculate::delSpace(string str) { //TESTED
    string temp=str;
    size_t pos=temp.find(" ");
    do{
        temp.erase(pos,1);
    } while((pos=temp.find(" ", pos+1))!=string::npos);
    return temp;
}

int calculate::index(char funcName) { //TESTED
    return toupper(funcName)-65;
}
