//C++ 
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100001], trace;
int start, k, cnt, ans, id = 0;

bool check(int iFrom, int iTo) 
{
    if (iFrom == iTo) return false;
    for (int i = 0; i < adj[iFrom].size(); ++i) 
    {
        if (adj[iFrom][i] == iTo) 
            return false;
    }
    return true;
}

bool checkTrace(int c) 
{
    for (int i = 0; i < trace.size(); ++i) 
    {
        if (trace[i] == c) 
            return false;
    }
    return true;
}

void inspectCycle(int i) 
{
    for (int j = 0; j < adj[i].size(); ++j) 
    {
        int ij = adj[i][j];
        if (cnt < k  && checkTrace(ij)) 
        {
            cnt++;
            trace.push_back(ij);
            if (ij == start) 
            {
                if (cnt == k) 
                    ans = 1;
            }
            else inspectCycle(ij);
            cnt--;
            trace.pop_back();
        }
    }
}

int main() 
{
    string fromAcount; 
    cin >> fromAcount;
    map <string, int> moneyFrom, moneyTo, identify; 
    priority_queue <string, vector<string>, greater<string> > pq;

    int numberTransaction = 0;
    int totalMoney = 0;
    
    while (fromAcount != "#") 
    {
        string toAcount; cin >> toAcount;
        int money; cin >> money;
        string timePoint, atm;
        cin >> timePoint >> atm;

        if (!moneyFrom[fromAcount] && !moneyTo[fromAcount]) 
        {
            pq.push(fromAcount);
            identify[fromAcount] = ++id;
        }
        moneyFrom[fromAcount] += money;
        if (!moneyTo[toAcount] && !moneyFrom[toAcount]) 
        {
            pq.push(toAcount);
            identify[toAcount] = ++id;
        }
        moneyTo[toAcount] += money;
        
        if (check(identify[fromAcount], identify[toAcount])) 
        {
            adj[identify[fromAcount]].push_back(identify[toAcount]);
        }
        numberTransaction++; 
        totalMoney += money;
        cin >> fromAcount;
    }

    string query; 
    cin >> query;
    while (query != "#") 
    {
        if (query == "?number_transactions") 
            cout << numberTransaction << "\n";
        
        else if (query == "?total_money_transaction") 
            cout << totalMoney << "\n";
        
        else if (query == "?list_sorted_accounts") 
        {
            while (!pq.empty()) 
            {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n";
        } 
        else if (query == "?total_money_transaction_from") 
        {
            string account; cin >> account;
            cout << moneyFrom[account] << "\n";
        } 
        else 
        {
            string account;
            cin >> account >> k;
            start = identify[account];
            ans = cnt = 0;
            inspectCycle(start);
            cout << ans << "\n";
        }
        cin >> query;
    }
    return 0;
}

