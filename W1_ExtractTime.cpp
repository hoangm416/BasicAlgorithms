//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    char s[20];
    cin >> s;
    if ((s[4] != '-') || (s[7] != '-') || (s[9] == ' '))
        cout << "INCORRECT";
    else if ((s[5]==49 && s[6]>50) || (s[8]==51 && s[9]>49) || (s[5]>=50) || (s[8]>=52))
        cout << "INCORRECT";
    
    else {
        for (int i = 0; i < 4; i++)
            cout << s[i]-48;
        if (s[5] == 48)
            cout << " " << s[6]-48;
        else cout << " " << s[5]-48 << s[6]-48;
        
        if (s[8] == 48)
            cout << " " << s[9]-48;
        else cout << " " << s[8]-48 << s[9]-48;
    }
    return 0;
}

