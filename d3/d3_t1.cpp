#include "../readfile.h"

using namespace std;

int main() 
{

    const int n = 323;
    readFile("input.txt",n);

    int x = 0;
    int y = 0;

    int trees = 0;

    while(y < n) 
    {
        string line = input[y];
        if(line[x] == '#') trees++;
        x = (x + 3) % line.length();
        y += 1;
    }
    cout << " no trees: " << trees << endl;
    return 0;
}