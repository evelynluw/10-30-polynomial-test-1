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
    cout<<getCommand(cin)<<endl;
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
    string _command = toupper(delSpace(command));
    for(unsigned int i = 0; i < 5; ++i) {
        size_t pos=0;
        if((pos = _command.find(commandArr[i])) != string::npos) {
            string exp = _command.substr(pos+commandArr[i].length()) ;
            switch (i) {
            case 0: //LET
                char funcName = exp[0];

                break;
            default:
                break;
            }
        }
    }
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

void calculate::algebra(string algebraExp) {

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
