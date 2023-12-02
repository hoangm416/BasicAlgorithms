//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n;
    double diff = 0;
    cin >> n;
    if ((n >= 0) && (n <= 50))
    {
        diff = 0;
        cout << "0.00";
    }
    else if ((n >= 51) && (n <= 100))
    {
        diff = 1728 * (n - 50) - 1786 * (n - 50);
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    else if ((n >= 101) && (n <= 200))
    {
        diff = -2900;
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    else if ((n >= 201) && (n <= 300))
    {
        diff = -2900;
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    else if ((n >= 301) && (n <= 400))
    {
        diff = -2900 + 2612 * (n - 300) - 2919 * (n - 300);
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    else if ((n >= 401) && (n <= 700))
    {
        diff = -33600 + 96 * (n - 400);
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    else 
    {
        diff = 899700 + 3457 * (n - 700) - 3015 * (n - 400);
        cout << setprecision(2) << fixed << diff * 1.1; 
    }
    
    return 0;
}

