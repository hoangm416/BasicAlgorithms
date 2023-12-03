#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int totalNumberOrders = 0;
    int totalRevenue = 0;
    int revenueOfShop[1000];
    int totalRevenueInPeriodhms[24][60][60];
    int totalRevenueInPeriodhm[24][60];
    int totalRevenueInPeriodh[24];
    int totalConsumeOfCustomerShop[1000][1000];

    memset(revenueOfShop, 0, sizeof(revenueOfShop));
    memset(totalRevenueInPeriodhms, 0, sizeof(totalRevenueInPeriodhms));
    memset(totalRevenueInPeriodhm, 0, sizeof(totalRevenueInPeriodhm));
    memset(totalRevenueInPeriodh, 0, sizeof(totalRevenueInPeriodh));
    memset(totalConsumeOfCustomerShop, 0, sizeof(totalConsumeOfCustomerShop));

    string customerId; cin >> customerId;
    while (customerId != "#") {
        string productId; cin >> productId;
        int price; cin >> price;
        string shopId, timePoint;
        cin >> shopId >> timePoint;

        ++totalNumberOrders;
        totalRevenue += price;
        revenueOfShop[(shopId[2] - '0') * 100 + (shopId[3] - '0') * 10 + shopId[4] - '0'] += price;
        int hour = (timePoint[0] - '0') * 10 + timePoint[1] - '0';
        int minute = (timePoint[3] - '0') * 10 + timePoint[4] - '0';
        totalRevenueInPeriodhms[hour][minute][(timePoint[6] - '0') * 10 + timePoint[7] - '0'] += price;
        totalRevenueInPeriodhm[hour][minute] += price;
        totalRevenueInPeriodh[hour] += price;
        totalConsumeOfCustomerShop[(customerId[2] - '0') * 100 + (customerId[3] - '0') * 10 + customerId[4] - '0']
                                  [(shopId[2] - '0') * 100 + (shopId[3] - '0') * 10 + shopId[4] - '0'] += price;

        cin >> customerId;
    }
    
    string query; cin >> query;
    while (query != "#") {
        if (query == "?total_number_orders") {
            cout << totalNumberOrders << "\n";
        } else if (query == "?total_revenue") {
            cout << totalRevenue << "\n";
        } else if (query == "?revenue_of_shop") {
            string shopId; cin >> shopId;
            cout << revenueOfShop[(shopId[2] - '0') * 100 + (shopId[3] - '0') * 10 + shopId[4] - '0'] << "\n";
        } else if (query == "?total_consume_of_customer_shop") {
            string cI, sI;
            cin >> cI >> sI;
            cout << totalConsumeOfCustomerShop[(cI[2] - '0') * 100 + (cI[3] - '0') * 10 + cI[4] - '0']
                                              [(sI[2] - '0') * 100 + (sI[3] - '0') * 10 + sI[4] - '0'] << "\n";
        } else {
            string fromTime, toTime;
            cin >> fromTime >> toTime;
            int result = 0;
            int fromHour = (fromTime[0] - '0') * 10 + fromTime[1] - '0';
            int fromMinute = (fromTime[3] - '0') * 10 + fromTime[4] - '0';
            int toHour = (toTime[0] - '0') * 10 + toTime[1] - '0';
            int toMinute = (toTime[3] - '0') * 10 + toTime[4] - '0';
            for (int i = fromHour + 1; i < toHour; ++i) {
                result += totalRevenueInPeriodh[i];
            }
            if (fromHour != toHour) {
                for (int i = fromMinute + 1; i < 60; ++i) {
                    result += totalRevenueInPeriodhm[fromHour][i];
                }
                for (int i = 0; i < toMinute; ++i) {
                    result += totalRevenueInPeriodhm[toHour][i];
                }  
                for (int i = (fromTime[6] - '0') * 10 + fromTime[7] - '0'; i < 60; ++i) {
                    result += totalRevenueInPeriodhms[fromHour][fromMinute][i];
                }
                for (int i = 0; i <= (toTime[6] - '0') * 10 + toTime[7] - '0'; ++i) {
                    result += totalRevenueInPeriodhms[toHour][toMinute][i];
                }      
            } else {
                for (int i = fromMinute + 1; i < toMinute; ++i) {
                    result += totalRevenueInPeriodhm[fromHour][i];
                }
                if (fromMinute != toMinute) {
                    for (int i = (fromTime[6] - '0') * 10 + fromTime[7] - '0'; i < 60; ++i) {
                        result += totalRevenueInPeriodhms[fromHour][fromMinute][i];
                    }
                    for (int i = 0; i <= (toTime[6] - '0') * 10 + toTime[7] - '0'; ++i) {
                        result += totalRevenueInPeriodhms[toHour][toMinute][i];
                    }
                } else {
                    for (int i = (fromTime[6] - '0') * 10 + fromTime[7] - '0'; i <= (toTime[6] - '0') * 10 + toTime[7] - '0'; ++i) {
                        result += totalRevenueInPeriodhms[fromHour][fromMinute][i];
                    }
                }
            }
            cout << result << "\n";
        }
        cin >> query;
    }
    return 0;
}

