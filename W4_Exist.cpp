//C++ 
#include <bits/stdc++.h> 
#include <set>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    set<int> s;
    for (int i = 0; i < n; i++) 
    {
        if (s.find(a[i]) != s.end()) 
            cout << "1" << endl;
        else 
        {
            cout << "0" << endl;
            s.insert(a[i]);
        }
    }
    return 0;
}

