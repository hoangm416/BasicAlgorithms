//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n, k, cnt = 0, sum = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < k; i++)
        sum += a[i];

    if (sum % 2 == 0) 
        cnt++;
    for (int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i-k];
        if (sum % 2 == 0) 
            cnt++;
    }
    
    cout << cnt;
    return 0;
}

