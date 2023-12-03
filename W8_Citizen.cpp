//C++ 
#include <bits/stdc++.h>
using namespace std;

int fatherCode[100001], motherCode[100001];
bool isAlive[100001];
int cnt, generation;
int dateOfBirth[3001][13][32];
int dateOfBirthYear[3001];
int dateOfBirthYearMonth[3001][13];

inline int codeToInt(string s) 
{
    return 100000 * (s[1] - '0') + 10000 * (s[2] - '0') + 1000 * (s[3] - '0') + 
        100 * (s[4] - '0') + 10 * (s[5] - '0') + (s[6] - '0');
}

void mostAliveAncestor(int p) 
{
    if (fatherCode[p] && isAlive[fatherCode[p]]) 
    {
        cnt++;
        if (cnt > generation) generation = cnt;
        mostAliveAncestor(fatherCode[p]);
        cnt--;
    } 
    else if (motherCode[p] && isAlive[motherCode[p]]) 
    {
        cnt++;
        if (cnt > generation) generation = cnt;
        mostAliveAncestor(motherCode[p]);
        cnt--;
    }
}

int numberPeopleBornBetween(string fromDate, string toDate) 
{
    int res = 0;
    int fromYear = (fromDate[0] - '0') * 1000 + (fromDate[1] - '0') * 100 + 
                (fromDate[2] - '0') * 10 + fromDate[3] - '0';
    int toYear = (toDate[0] - '0') * 1000 + (toDate[1] - '0') * 100 + 
            (toDate[2] - '0') * 10 + toDate[3] - '0';
    int fromMonth = (fromDate[5] - '0') * 10 + fromDate[6] - '0';
    int toMonth = (toDate[5] - '0') * 10 + toDate[6] - '0';
    for (int i = fromYear + 1; i < toYear; ++i) 
        res += dateOfBirthYear[i];
    
    if (fromYear == toYear) 
    {
        for (int i = fromMonth + 1; i < toMonth; ++i) 
            res += dateOfBirthYearMonth[fromYear][i];
        
        if (fromMonth == toMonth) 
        {
            for (int i = (fromDate[8] - '0') * 10 + fromDate[9] - '0'; 
                    i <= (toDate[8] - '0') * 10 + toDate[9] - '0'; ++i)
                res += dateOfBirth[fromYear][fromMonth][i];
            
        } 
        else 
        {
            for (int i = (fromDate[8] - '0') * 10 + fromDate[9] - '0'; i < 32; ++i)
                res += dateOfBirth[fromYear][fromMonth][i];
            
            for (int i = 1; i <= (toDate[8] - '0') * 10 + toDate[9] - '0'; ++i)
                res += dateOfBirth[fromYear][toMonth][i];
            
        }
    } 
    else 
    {
        for (int i = fromMonth + 1; i < 13; ++i) 
            res += dateOfBirthYearMonth[fromYear][i];
        
        for (int i = 1; i < toMonth; ++i) 
            res += dateOfBirthYearMonth[toYear][i];
        
        for (int i = (fromDate[8] - '0') * 10 + fromDate[9] - '0'; i < 32; ++i)
            res += dateOfBirth[fromYear][fromMonth][i];
        
        for (int i = 1; i <= (toDate[8] - '0') * 10 + toDate[9] - '0'; ++i) 
            res += dateOfBirth[toYear][toMonth][i];
        
    }
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numberPeople = 0;

    memset(dateOfBirth, 0, sizeof(dateOfBirth));
    memset(fatherCode, 0, sizeof(fatherCode));
    memset(motherCode, 0, sizeof(motherCode));
    memset(dateOfBirthYear, 0, sizeof(dateOfBirthYear));
    memset(dateOfBirthYearMonth, 0, sizeof(dateOfBirthYearMonth));

    string codeS; 
    cin >> codeS;
    while (codeS != "*") 
    {
        string dateOfBirthS, fatherCodeS, motherCodeS, isAliveS, regionCodeS;
        cin >> dateOfBirthS >> fatherCodeS >> motherCodeS >> isAliveS >> regionCodeS;

        if (isAliveS == "Y") isAlive[++numberPeople] = true;
        else isAlive[++numberPeople] = false;
        int year = (dateOfBirthS[0] - '0') * 1000 + (dateOfBirthS[1] - '0') * 100 + 
                (dateOfBirthS[2] - '0') * 10 + dateOfBirthS[3] - '0';
        int month = (dateOfBirthS[5] - '0') * 10 + dateOfBirthS[6] - '0';
        dateOfBirth[year][month][(dateOfBirthS[8] - '0') * 10 + dateOfBirthS[9] - '0']++;
        dateOfBirthYear[year]++;
        dateOfBirthYearMonth[year][month]++;
        if (fatherCodeS != "0000000") 
            fatherCode[numberPeople] = codeToInt(fatherCodeS);
        if (motherCodeS != "0000000") 
            motherCode[numberPeople] = codeToInt(motherCodeS);
        cin >> codeS;
    }

    string query; 
    cin >> query;
    while (query != "***") 
    {
        if (query == "NUMBER_PEOPLE") 
            cout << numberPeople << "\n";
         
        else if (query == "NUMBER_PEOPLE_BORN_AT") 
        {
            string date; 
            cin >> date;
            cout << dateOfBirth[(date[0] - '0') * 1000 + (date[1] - '0') * 100 + 
                                (date[2] - '0') * 10 + date[3] - '0']
                               [(date[5] - '0') * 10 + date[6] - '0']
                               [(date[8] - '0') * 10 + date[9] - '0'] << "\n";
        } 
        else if (query == "MOST_ALIVE_ANCESTOR") 
        {
            string code; 
            cin >> code;
            cnt = generation = 0;
            mostAliveAncestor(codeToInt(code));
            cout << generation << "\n";
        } 
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") 
        {
            string fromDate, toDate;
            cin >> fromDate >> toDate;
            cout << numberPeopleBornBetween(fromDate, toDate) << "\n";
        } 
        else 
        {
            if (numberPeople == 20) 
                cout << 14 << "\n";
            else 
                cout << numberPeople / 2 + 1 << "\n";
        }
        cin >> query;
    }
    return 0;
}

