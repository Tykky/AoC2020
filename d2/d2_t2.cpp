#include "../readfile.h"
#include <unordered_map>


using namespace std;

int main() 
{

    const int n = 1000;
    readFile("input.txt",n);
    int validcount = 0;

    for (size_t i = 0; i < n; i++)
    {
        string line = input[i];
        int dash = 0;
        int end = 0;
        int low = 0;
        int high = 0;
        char c = 0;
        string password = "";
        for (size_t j = 0; j < line.length(); j++)
        {
            if(line[j] == '-') dash = j;
            if(line[j] == ':')  {
                end = j;
                low = stoi(line.substr(0,dash));
                high = stoi(line.substr(dash+1,end-dash-3));
                c = line[end-1];
                password = line.substr(end+2, line.length() - end+2);
                break;
            }
        }
        if(password[low-1] == c ^ password[high-1] == c) validcount++;
    }
    cout << validcount << endl;
    return 0;
}