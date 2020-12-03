#include "../readfile.h"
#include <unordered_map>

using namespace std;

int main() {
    
    const int sum = 2020;
    const int n = 200;
    readFile("input.txt",n);
    unordered_map<int,int> map;

    for (size_t i = 0; i < n; i++)
    {
        int a = stoi(input[i]);
        auto it = map.find(sum-a);
        if (it != map.end()) {
            int b = stoi(input[(*it).second]);
            cout << a*b << endl;
        }   else {
            map.insert({a,i});
        }
    }
    
}