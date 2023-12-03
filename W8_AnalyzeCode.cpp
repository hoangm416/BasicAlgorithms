//C++ 
#include <bits/stdc++.h>
using namespace std;

int timePoint[24][60][60];
int timePointHour[24];
int timePointHourMinute[24][60];

inline int userIdToInt(string s) {
    return (s[1] - '0') * 1000 + (s[2] - '0') * 100 + 
            (s[3] - '0') * 10 + s[4] - '0';
}

inline int problemIdToInt(string s) {
    return (s[1] - '0') * 10 + s[2] - '0';
}

int numberSubmissionPeriod(string fromTimePoint, string toTimePoint) 
{
    int res = 0;
    int fromHour = (fromTimePoint[0] - '0') * 10 + fromTimePoint[1] - '0';
    int toHour = (toTimePoint[0] - '0') * 10 + toTimePoint[1] - '0';
    int fromMinute = (fromTimePoint[3] - '0') * 10 + fromTimePoint[4] - '0';
    int toMinute = (toTimePoint[3] - '0') * 10 + toTimePoint[4] - '0';
    int fromSecond = (fromTimePoint[6] - '0') * 10 + fromTimePoint[7] - '0';
    int toSecond = (toTimePoint[6] - '0') * 10 + toTimePoint[7] - '0';
    for (int i = fromHour + 1; i < toHour; ++i) 
        res += timePointHour[i];
    
    if (fromHour == toHour) 
    {
        for (int i = fromMinute + 1; i < toMinute; ++i) 
            res += timePointHourMinute[fromHour][i];
        
        if (fromMinute == toMinute) 
        {
            for (int i = fromSecond; i <= toSecond; ++i) 
                res += timePoint[fromHour][fromMinute][i];
        } 
        else 
        {
            for (int i = fromSecond; i < 60; ++i) 
                res += timePoint[fromHour][fromMinute][i];
            
            for (int i = 0; i <= toSecond; ++i) 
                res += timePoint[fromHour][toMinute][i];
        }
    } 
    else 
    {
        for (int i = fromMinute + 1; i < 60; ++i) 
            res += timePointHourMinute[fromHour][i];
        
        for (int i = 0; i < toMinute; ++i) 
            res += timePointHourMinute[toHour][i];
        
        for (int i = fromSecond; i < 60; ++i) 
            res += timePoint[fromHour][fromMinute][i];
        
        for (int i = 0; i <= toSecond; ++i) 
            res += timePoint[toHour][toMinute][i];
    }
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int totalNumberSubmissions = 0;
    int numberErrorSubmissions = 0;

    int numberErrorSubmissionOfUser[10000];
    int pointOfUser[10000][100];
    int totalPointOfUser[10000];

    memset(numberErrorSubmissionOfUser, 0, sizeof(numberErrorSubmissionOfUser));
    memset(pointOfUser, 0, sizeof(pointOfUser));
    memset(totalPointOfUser, 0, sizeof(totalPointOfUser));
    memset(timePoint, 0, sizeof(timePoint));
    memset(timePointHour, 0, sizeof(timePointHour));
    memset(timePointHourMinute, 0, sizeof(timePointHourMinute));

    string userIdS; 
    cin >> userIdS;
    while (userIdS != "#") 
    {
        string problemIdS, timePointS, statusS;
        cin >> problemIdS >> timePointS >> statusS;
        int point; 
        cin >> point;
        totalNumberSubmissions++;
        int userId = userIdToInt(userIdS);
        int problemId = problemIdToInt(problemIdS);
        if (statusS == "ERR") 
        {
            numberErrorSubmissions++;
            numberErrorSubmissionOfUser[userId]++;
        } 
        else if (point > pointOfUser[userId][problemId]) 
        {
            totalPointOfUser[userId] += (point - pointOfUser[userId][problemId]);
            pointOfUser[userId][problemId] = point;
        }
        int hour = (timePointS[0] - '0') * 10 + timePointS[1] - '0';
        int minute = (timePointS[3] - '0') * 10 + timePointS[4] - '0';
        int second = (timePointS[6] - '0') * 10 + timePointS[7] - '0';
        timePoint[hour][minute][second]++;
        timePointHour[hour]++;
        timePointHourMinute[hour][minute]++;

        cin >> userIdS;
    }

    string query; 
    cin >> query;
    while (query != "#") 
    {
        if (query == "?total_number_submissions") 
            cout << totalNumberSubmissions << "\n";
        
        else if (query == "?number_error_submision") 
            cout << numberErrorSubmissions << "\n";
        
        else if (query == "?number_error_submision_of_user") 
        {
            string userId; 
            cin >> userId;
            cout << numberErrorSubmissionOfUser[userIdToInt(userId)] << "\n";
        } 
        else if (query == "?total_point_of_user") 
        {
            string userId; 
            cin >> userId;
            cout << totalPointOfUser[userIdToInt(userId)] << "\n";
        } 
        else 
        {
            string fromTimePoint, toTimePoint;
            cin >> fromTimePoint >> toTimePoint;
            cout << numberSubmissionPeriod(fromTimePoint, toTimePoint) << "\n";
        }
        cin >> query;
    }
    
    return 0;
}

