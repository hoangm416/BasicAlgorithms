//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    char s[10];
    cin >> s;
    if ((s[2] != ':') || (s[5] != ':') || (s[7] == ' '))
        cout << "INCORRECT";
    else if ((s[0] >= 51) || (s[3] >= 54) || (s[6] >= 54) || (s[0]==50 && s[1]>51))
        cout << "INCORRECT";
    else {
        int res = (s[0]-48) * 36000 + (s[1]-48) * 3600 + (s[3]-48) * 600
                    + (s[4]-48) * 60 + (s[6]-48) * 10 + (s[7]-48);
        cout << res;
    }
    return 0;
}

