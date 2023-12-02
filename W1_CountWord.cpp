//C++ 
#include <iostream>
#include <string>
using namespace std;

int countWords(string str) {
    int count = 0;
    bool isWord = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            isWord = false;
        }
        else if (!isWord) {
            isWord = true;
            count++;
        }
    }
    return count;
}

int main() 
{
    string input;
    string output = "";

    while (getline(cin, input))
    {
        output += input + "\n";
    }
    
    cout << countWords(output);
    return 0;
}

