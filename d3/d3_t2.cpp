#include "../readfile.h"

using namespace std;

int numberOfTrees(int right, int down) 
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
        x = (x + right) % line.length();
        y += down;
    }
    return trees;
}

int main() 
{
    int slopes[][2] = {{1,1},{3,1},{5,1},{7,1},{1,2}};
    long product = 1;
    for(int *i : slopes) 
    {
        product *= numberOfTrees(i[0],i[1]);
    }
    cout << product << endl;
}