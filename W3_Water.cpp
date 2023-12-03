//C++ 
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int bfs(int a, int b, int c) {
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            if (x == c || y == c || x + y == c) {
                return steps;
            }
            // Fill jug 1
            if (x < a && !visited.count({a, y})) {
                q.push({a, y});
                visited.insert({a, y});
            }
            // Fill jug 2
            if (y < b && !visited.count({x, b})) {
                q.push({x, b});
                visited.insert({x, b});
            }
            // Empty jug 1
            if (x > 0 && !visited.count({0, y})) {
                q.push({0, y});
                visited.insert({0, y});
            }
            // Empty jug 2
            if (y > 0 && !visited.count({x, 0})) {
                q.push({x, 0});
                visited.insert({x, 0});
            }
            // Pour from jug 1 to jug 2
            if (x > 0 && y < b) {
                int amount = min(x, b - y);
                if (!visited.count({x - amount, y + amount})) {
                    q.push({x - amount, y + amount});
                    visited.insert({x - amount, y + amount});
                }
            }
            // Pour from jug 2 to jug 1
            if (y > 0 && x < a) {
                int amount = min(y, a - x);
                if (!visited.count({x + amount, y - amount})) {
                    q.push({x + amount, y - amount});
                    visited.insert({x + amount, y - amount});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << bfs(a, b, c) << endl;
    return 0;
}

