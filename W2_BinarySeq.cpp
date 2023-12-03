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

void Try (int k)
{
    for (int v = 0; v <= 1; v++)
    {
        x[k] = v;
        if (k == n) solution();
        else Try (k+1);
    }
}
int main() 
{ 
    cin >> n;
    Try (1);
    return 0;
}

