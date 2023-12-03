//C++ 
#include <bits/stdc++.h> 
#include <string>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) 
    {
        cin >> s;
        int k = s.length();
        int h = 0;
        for (int j = 0; j < k; j++) 
            h = (h * 256 + s[j]) % m;

        cout << h << endl;
    }

    return 0;
}

