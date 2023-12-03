//C++ 
#include <bits/stdc++.h> 
#include <vector>
using namespace std;
int main() 
{ 
    int q = 0, n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a+n);
    int i = 0; 
    int j = n-1;
    while(i != j)
    {
        if ((a[i]+a[j]) == m)
        {
            q++;
            i++, j--;
        }
        else if ((a[i]+a[j]) < m)
            i++;
        else j--;
    }
    cout << q;
    return 0;
}

