//C++ 
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

int main() 
{ 
    queue<int> q;
    char opera[10];
    while (cin >> opera)
    {
        if (opera[0] == '#')
            break;
        else if (opera[1] == 'U'){
            int v;
            cin >> v;
            q.push(v);
        }
        else if (opera[1] == 'O'){
            if (q.empty())
                cout << "NULL" << endl;
            else{
                cout << q.front() << endl;
                q.pop();
            }
            
        }
        
    }
    
    return 0;
}

