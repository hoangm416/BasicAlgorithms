//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n;
    cin >> n;
    for (int i = 0; i <= 999/n; i++)
    {
        int tmp = n * i;
        if ((tmp >= 100) && (tmp <= 999))
            cout << tmp << " ";
    }
    return 0;
    
}

