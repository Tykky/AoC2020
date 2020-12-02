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
        int a = std::stoi(input[i]);
        for (size_t j = 0; j < n; j++)
        {
            int b = std::stoi(input[j]);
            auto it = map.find(sum-a-b);
            if(it != map.end()) {
                int c = std::stoi(input[(*it).second]);
                cout << a*b*c << endl;
                goto end;
            } else {
                map.insert({b,j});
            }
        }
    }
    end:;
}