#include <iostream>
#include <fstream>

#define readFile(filename, size)\ 
    std::ifstream file(filename);\
    std::string line;\
    int input[size];\
    int i = 0;\
    if (file.is_open()) {\
        while (getline(file,line)) {\
            input[i] = std::stoi(line);\
            i++;\
        }\
        file.close();\
    }  