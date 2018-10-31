#include <iostream>
#include <string>
#include "expression.h"

using namespace std;

int main(int argc, char *argv[])
{
    try {
        expression program;
        program.run(argc, argv);
        return 0;
    } catch (...) {
        cout<<"An error occurred";
    }
}







