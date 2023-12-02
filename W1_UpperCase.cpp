//C++ 
#include <bits/stdc++.h> 
#include <string>
using namespace std;

int main()
{
    string input;
    string output = "";

    while (getline(cin, input))
    {
        output += input + "\n";
    }
    transform(output.begin(), output.end(), output.begin(), ::toupper);
    cout << output;

    return 0;
}

