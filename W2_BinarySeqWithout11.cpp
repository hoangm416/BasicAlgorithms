//C++ 
#include <bits/stdc++.h> 
using namespace std;

int n, x[21];
void solution()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

bool check (int v, int k)
{
    if ((x[k-1] == 1) && (v == 1))
        return false;
    return true;
}

void Try (int k)
{
    for (int v = 0; v <= 1; v++){
        if (check(v, k))
        {
            x[k] = v;
            if (k == n) solution();
            else Try (k+1);
        }
    }
}

int main() 
{ 
    cin >> n;
    x[0] = 0;
    Try (1);
    return 0;
}

