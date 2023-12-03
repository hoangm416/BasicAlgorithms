//C++ 
#include <bits/stdc++.h> 
#include <set>
using namespace std;

int main() 
{
    string key;
    
    set<string> data;
    while (cin >> key) 
    {
        if (key == "*")
            break;
        data.insert(key);
    }
    
    string cmd;
    while (cin >> cmd >> key)
    {
        if (cmd == "***")
            break;
        
        else if (cmd == "find")
            cout << data.count(key) << endl;
        else 
        {
            auto result = data.insert(key);
            cout << result.second << endl;
        }
            
    }
    return 0;
}

