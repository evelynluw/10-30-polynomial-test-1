#include "expression.h"

//PUBLIC

//..CONSTRUCTOR

expression::expression()
{
    //initialization done in class variable declarations
}

//..MAIN PROGRAM

void expression::run(int argc, char *argv[]) {
    bool record = false;
    switch (argc) {
    case 1:
        break;
    case 2: { //TESTED
        if(string(argv[1]) == "/h" ||
                string(argv[1]) == "/?") {
            help();
        } else {
            string filename(argv[1]);
            load(filename);
        }
        break;
    }
    case 3: {
        if(toUpper(string(argv[1]))=="EXECUTE") { //TESTED
            execute(string(argv[2]));
        }
        if(toUpper(string(argv[1]))=="RECORD") {
            record = true;
            cout<<"recording to "<<argv[2]<<endl;
        }
        break;
    }
    default:
        cout<<"argument error"<<endl;
        exit(1);
        //throw error
        break;
    }
    while(1) {
        prompt();
        string line = getCommand(cin);
        execCommand(line);
        if(record)
            recordToFile(argv[2], line);
    }
}

//..TESTING
void expression::test() {
    saveStringToFile("test.txt", "the fist line");
    saveStringToFile("test.txt", "the second line", true);
}

//PRIVATE

//..MAIN FUNCTIONS

void expression::prompt() { //TESTED
    cout<<"INPUT: ";
}

void expression::help() {
    cout<<"Examples for INPUT: \n"
       << "LET F = 2X + 4 \n"
       << "EVAL F(1/4) \n"
       << "PRINT F \n"
       << "LOAD filename.exp \n"
       << "SAVE filename.exp \n"
       << "NEWTON F 5 \n"
       << "F = G + H \n"
       << "\n"
       << "Examples for command line arguments: \n"
       << "test1.exp \n"
       << "EXECUTE script1.spt \n"
       << "RECORD record1.spt \n"
       << "/h \n"
       << endl;
}

string expression::getCommand(istream& in) { //TESTED: cout<<getCommand(cin)<<endl;
    if(in.peek()=='\n')
        exit(1);
    string temp;
    getline(in, temp);
    return temp;
}

void expression::execCommand(string command) {
    /* sample argm:
     * LET F = 2X + 4
     * EVAL F(1/4)
     * PRINT F
     * LOAD filename.exp
     * SAVE filename.exp
     * NEWTON F 5
     * F = G + H
     */
    string noSpaceCommand = delSpace(command),
            upperCommand = toUpper(noSpaceCommand);
    for(unsigned int i = 0; i < 6; ++i) {
        size_t pos=0;
        if((pos = upperCommand.find(commandArr[i])) != string::npos) {
            string exp = noSpaceCommand.substr(pos+commandArr[i].length()) ;
            switch (i) {
            case 0: //LET, exp = "F=2X+4", TESTED
            {
                char funcName = exp[0];
                exp.erase(0,2); //"2X+4"
                let(funcName, exp);
                break;
            }
            case 1: //EVAL, exp = "F(1/4)", TESTED
            {
                char funcName = exp[0];
                fraction value(exp.substr(2,exp.length()-1-2));
                eval(funcName, value); //value = 1/4
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
            case 5: //NEWTON, exp = "F10.5"
            {
                char funcName = exp[0];
                fraction initGuess(exp.substr(1));
                newton(funcName, initGuess);
            }
            default:
                break;
            }
            return;
        }
    }

    algebra(noSpaceCommand); //"F=G+H", TESTED
}

void expression::let(char funcName, string exp) { //NOT FULLY WORKING - setExp...
    /* sample argm:
     * 2X+4
     */
    exps[index(funcName)].setExp(exp);
    print(funcName);
}

void expression::eval(char funcName, fraction value) { //PARTIALLY TESTED
    stringstream ss;
    string temp;
    ss<<funcName<<'('<<value<<") = "
     <<exps[index(funcName)].evaluate(value);
    getline(ss,temp);
    cout<<temp<<endl;
}

void expression::print(char funcName) { //TESTED
    stringstream ss;
    string temp;
    ss<<funcName<<" = "<<exps[index(funcName)];
    getline(ss,temp);
    cout<<temp<<endl;
}

void expression::load(string& filename) {
    ifstream ifs;
    string line;
    if(filename.empty()) {
        cout<<"invalid filename"<<endl;
        return;
        //throw error
    }
    if(filename.find(".exp")>filename.size())
        filename+=".exp";
    ifs.open(filename);
    if(ifs.fail()) {
        cout<<"file does not exist"<<endl;
        return;
        //throw error
    }
    cout<<"loaded "<<filename<<endl;
    while(!ifs.eof())
    {
        stringstream ss;
        getline(ifs, line);
        if(!line.empty()){
            ss<<"LET "<<line;
            getline(ss, line);
//            cout<<"##line: "<<line<<endl;
            execCommand(line);
        }
    }
}

void expression::save(string& filename) {
    ifstream ifs;
    ofstream ofs;
    string line;
    if(filename.empty()) {
        cout<<"invalid filename"<<endl;
        return;
        //throw error
    }
    if(filename.find(".exp")>filename.size())
        filename+=".exp";
    ifs.open(filename);
    if(!ifs.fail()) {
        cout<<"file already exists, overwrite?"<<endl;
        getline(cin, line);
        if(toupper(line[0])!='Y')
            return;
    }
    ofs.open(filename);
    for(char i = 'A'; i <= 'Z'; ++i) {
        ofs<<i<<" = "<<exps[index(i)]<<endl;
    }
    cout<<"saved to "<<filename<<endl;
}

void expression::algebra(string algebraExp) { //TESTED
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
        print(fn1);
        return;
    }
    if((pos = algebraExp.find('\''))!= string::npos) { //TESTED
        char fn1 = algebraExp[0],
                fn2 = algebraExp[2];
        int derCount = 1;
        while((pos = algebraExp.find('\'', pos+1))!= string::npos)
            derCount++;
        exps[index(fn1)]= nthDerivative(exps[index(fn2)], derCount);
        print(fn1);
        return;
    }

    //throw error here

}

void expression::execute(string filename) {
    ifstream ifs;
    string line;
    if(filename.empty()) {
        cout<<"invalid filename"<<endl;
        return;
        //throw error
    }
    if(filename.find(".spt")>filename.size())
        filename+=".spt";
    ifs.open(filename);
    if(ifs.fail()) {
        cout<<"file does not exist"<<endl;
        return;
        //throw error
    }
    cout<<"loaded "<<filename<<endl;
    while(!ifs.eof())
    {
        stringstream ss;
        getline(ifs, line);
        if(!line.empty()){
            ss<<line;
            getline(ss, line);
            cout<<"##line: "<<line<<endl;
            execCommand(line);
        }
    }
}

void expression::recordToFile(string filename, string line) {
    if(filename.find(".spt")>filename.size())
        filename+=".spt";
    saveStringToFile(filename, line, true);
}

void expression::newton(char funcName, fraction initGuess) {
    polynomial exp1(exps[index(funcName)]),
            exp2 = firstDerivative(exp1);
    double x = initGuess.evaluate();
    double epsilon = 0.1;
    double h = exp1.evaluate(x) / exp2.evaluate(x);
    while(abs(h)>= epsilon) {
        h = exp1.evaluate(x) / exp2.evaluate(x);
        x = x - h;
    }
    cout<<"root of "<<funcName<<" is "<<x<<endl;
}


//..ADDITIONAL FUNCTIONS

string expression::toUpper(string str) { //TESTED
    string temp;
    for(string::iterator it=str.begin(); it!=str.end(); ++it){
        temp.push_back(toupper(*it));
    }
    return temp;
}

string expression::delSpace(string str) { //TESTED
    string temp=str;
    size_t pos=0;
    while((pos=temp.find(" ", pos+1))!=string::npos) {
        temp.erase(pos,1);
    }
    return temp;
}

int expression::index(char funcName) { //TESTED
    return toupper(funcName)-65;
}

void expression::saveStringToFile(string filename, string line, bool append) {
    ofstream ofs;
    if(append)
        ofs.open(filename, ios_base::app);
    else
        ofs.open(filename);
    ofs<<line<<endl;
    //check if there is line endings
}

void expression::askString(string prompt, string& theString) {
    cout<<prompt;
    cin>>theString;
}

