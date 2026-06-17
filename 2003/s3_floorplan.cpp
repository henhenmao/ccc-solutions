

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void print(vector<vector<char>>& plan) {
    int n = plan.size();
    for(int i = 0; i < n; i++) {
        for(char c : plan[i])
            cout << c << " ";
        cout << endl;
    }
}

void bfs(vector<vector<char>>& plan, int r, int c, int i, int j, vector<int>& areas) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    plan[i][j] = '#';

    int tempArea = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& [a, b] : directions) {
            int next_x = x+a, next_y = y+b;
            if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c || plan[next_x][next_y] == '#' || plan[next_x][next_y] == 'I') continue; 
            
            q.push({next_x, next_y});
            plan[next_x][next_y] = '#';
            tempArea++;
        }
    }
    areas.push_back(tempArea);
}

int main() {
    int flooring, r, c;
    cin >> flooring;
    cin >> r;
    cin >> c;
    vector<vector<char>> plan(r);
    string line;

    for (int i = 0; i < r; i++) {
        cin >> line;
        for (char ch : line) {
            plan[i].push_back(ch);
        }
    }

    // print(plan);

    vector<int> areas;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (plan[i][j] == 'I' || plan[i][j] == '#') continue;
            bfs(plan, r, c, i, j, areas);
        }
    }

    sort(areas.begin(), areas.end(), greater<int>());
    
    int rooms = 0;
    int i = 0;
    int asize = areas.size();
    while (i < asize) {
        if (flooring - areas[i] < 0) break;
        rooms++;
        flooring-=areas[i];
        i++;
    }

    // for (int a : areas) {
    //     cout << a << endl;
    // }

    if (rooms == 1) {
        cout << rooms << " room, " << flooring << " square metre(s) left over" << endl;
    } else {
        cout << rooms << " rooms, " << flooring << " square metre(s) left over" << endl;
    }

    
    return 0;
}