#include "../readfile.h"
#include <unordered_map>
#include <vector>

using namespace std;

bool isvalid(unordered_map<string,string> passport) {
    const string keys[] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    bool returnval = true;
    for(string key : keys) {
        if(passport.find(key) == passport.end()) {
            returnval = false;
        }
    }
    return returnval;
}

void parsePassports(vector<unordered_map<string,string>> &passports) {
    const int n = 1130;
    readFile("input.txt", n);
    unordered_map<string, string> passport;

    for (size_t i = 0; i < n; i++) {
        string line = input[i];
        string key = "";
        string value = "";
        bool current_char_is_value = false;
        for (size_t j = 0; j < line.length(); j++) {
            if (line[j] == ':') {
                key = line.substr(j-3,3);
                current_char_is_value = true;
            }
            if (current_char_is_value) {
                if (line[j] != ' ') {
                    value += line[j];
                } else {
                    passport.insert({key,value});
                    current_char_is_value = false;
                    value = "";
                    key = "";
                }
            }
            if (j == line.length()-1) {
                passport.insert({key,value});
                current_char_is_value = false;
                value = "";
                key = "";
            }
        }
        if (line == "") {
            passports.push_back(passport);
            passport = {};
        }
    }
}

int main() {
    int validpasssports = 0;
    vector<unordered_map<string,string>> passports;
    parsePassports(passports);
    for(auto passport : passports) {
        if(isvalid(passport)) validpasssports++;
    }
    cout << validpasssports << endl;
}