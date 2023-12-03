//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string P1, P2, T;
    getline(cin, P1);
    cin.ignore();
    getline(cin, P2);
    cin.ignore();
    getline(cin, T);

    string result;
    size_t start = 0;
    size_t end = T.find(P1);
    while (end != string::npos) 
	{
        result += T.substr(start, end - start) + P2;
        start = end + P1.size();
        end = T.find(P1, start);
    }
    result += T.substr(start);

    cout << result;

    return 0;
}
