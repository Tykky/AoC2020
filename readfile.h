#include <iostream>
#include <fstream>

#define readFile(filename, size)\
    std::ifstream file(filename);\
    std::string line;\
    std::string input[size];\
    int i = 0;\
    if (file.is_open()) {\
        while (getline(file,line)) {\
            input[i] = line;\
            i++;\
        }\
        file.close();\
    }
