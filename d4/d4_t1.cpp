#include "../readfile.h"
#include <unordered_map>
#include <vector>

using namespace std;

const string keys[] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};

bool isvalid(unordered_map<string,string> passport) 
{
    for(string key : keys) 
    {
        if(passport.find(key) == passport.end()) 
        {
            return false;
        }
    }
    return true;
}

void insertFieldToPassport(string &key, string &value, unordered_map<string,string> &passport) {
    passport.insert({key,value});
    key = "";
    value = "";
}

void parsePassports(const string filename, const int n, vector<unordered_map<string,string>> &passports) {
    readFile(filename, n);
    unordered_map<string, string> passport;

    for (size_t i = 0; i < n; i++) 
    {
        string line = input[i];
        string key = "";
        string value = "";
        bool current_char_is_value = false;
        for (size_t j = 0; j < line.length(); j++)
        {
            if (line[j] == ':')
            {
                key = line.substr(j-3,3);
                current_char_is_value = true;
            } else if (current_char_is_value) 
            {
                value += line[j];
            }
            if (j == line.length()-1 || line[j] == ' ') 
            {
                insertFieldToPassport(key, value, passport);
                current_char_is_value = false;
            }
        }
        if (line == "") 
        {
            passports.push_back(passport);
            passport = {};
        }
    }
}

int main() 
{
    int validpasssports = 0;
    vector<unordered_map<string,string>> passports;
    parsePassports("input.txt", 1130, passports);
    for(auto passport : passports) 
    {
        if(isvalid(passport)) validpasssports++;
    }
    cout << validpasssports << endl;
}