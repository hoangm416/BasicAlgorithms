//C++ 
#include <bits/stdc++.h> 
#include <stack>
using namespace std;

int main() 
{ 
    stack<int> st;
    char opera[10];
    while (cin >> opera)
    {
        if (opera[0] == '#')
            break;
        else if (opera[1] == 'U'){
            int v;
            cin >> v;
            st.push(v);
        }
        else if (opera[1] == 'O'){
            if (st.empty())
                cout << "NULL" << endl;
            else{
                cout << st.top() << endl;
                st.pop();
            }
            
        }
        
    }
    
    return 0;
}

