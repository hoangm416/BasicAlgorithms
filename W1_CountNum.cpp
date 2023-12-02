//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n, c_odd = 0, c_even = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            c_even ++;
        else c_odd ++;
    }
    cout << c_odd << " " << c_even;
    return 0;
}

