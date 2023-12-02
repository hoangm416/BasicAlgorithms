//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    float a, b, c, delta, x1, x2;
    cin >> a >> b >> c;
    if(a == 0) {
        if(b == 0) {
            if (c == 0) {
                cout << "NO SOLUTION" << endl;
            } else {
                cout << "NO SOLUTION" << endl;
            }
        } else {
            cout << setprecision(2) << fixed << -c/b << endl;
        }
    } 
    else {
        delta = b*b - 4*a*c;
        if(delta > 0) {
            x1 = (-b-sqrt(delta))/(2*a);
            x2 = (-b+sqrt(delta))/(2*a);
            cout << setprecision(2) << fixed << x1 << " ";
            cout << setprecision(2) << fixed << x2 << endl;
        } else if ( delta == 0) {
            cout << setprecision(2) << fixed << -b/(2*a) << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    return 0;
}

