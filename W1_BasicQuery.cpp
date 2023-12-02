//C++ 
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    char query[21];
    while (cin >> query) 
    {
        if (query[0] == '*' && query[1] == '*') 
            break;
        
        else if (query[0] == 's')
        {
            int sum = 0;
            for (int k = 0; k < n; k++) 
            {
                sum += arr[k];
            }
            cout << sum << endl;
        }
        
        else if (query[8] != '-')
        {
            if (query[0] == 'f') 
            {
                if (query[6] == 'i') 
                    cout << *min_element(arr, arr + n) << endl;
                else 
                    cout << *max_element(arr, arr + n) << endl;
            }
        }
        
        else if (query[8] == '-') 
        {
            if (query[9] == 's') 
            {
                int i, j;
                cin >> i >> j;
                cout << *max_element(arr + i - 1, arr + j) << endl;
            } 
        }
        
    }

    return 0;
}

