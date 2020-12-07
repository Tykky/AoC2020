#include "../readfile.h"
#include <unordered_map>
#include <vector>

using namespace std;

const string keys[] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};

bool isvalid(unordered_map<string,string> passport) 
{
    string values[7];
    for (size_t i = 0; i < 7; i++)
    {
        auto it = passport.find(keys[i]);
        string value = "";
        if(it != passport.end()) value = it->second;
        values[i] = value;
    }

    const int byr = 0;
    const int iyr = 1;
    const int eyr = 2;
    const int hgt = 3;
    const int hcl = 4;
    const int ecl = 5;
    const int pid = 6;

    if(!(values[0] != "" && stoi(values[byr]) >= 1920 && stoi(values[byr]) <= 2002)) return false;
    if(!(values[1] != "" && stoi(values[iyr]) >= 2010 && stoi(values[iyr]) <= 2020)) return false;
    if(!(values[2] != "" && stoi(values[eyr]) >= 2020 && stoi(values[eyr]) <= 2030)) return false;

    if(values[hgt].length() <= 2)
    {
        return false;
    } else 
    {
        int value = stoi(values[3].substr(0,values[3].length()-2));
        string unit = values[3].substr(values[3].length()-2,2);
        if(unit == "cm" && !(value >= 150 && value <= 193)) return false;
        if(unit == "in" && !(value >= 59 && value <= 76)) return false;
    }
    if(!(values[4][0] == '#' && values[4].size() == 7)) // hcl
    { 
        return false;
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