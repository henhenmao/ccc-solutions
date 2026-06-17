
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

void print(const vector<vector<int>>& graph) {
    for (size_t i = 0; i < graph.size(); i++) {
        cout << "Row " << i << ": ";
        for (size_t j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

bool bfs(vector<vector<int>>& graph, int root, int target, int n) {
    queue<int> q;
    q.push(root);
    vector<bool> visited(n, false);
    visited[root] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // cout << "currently looking at node " << curr << endl;

        if (curr == target) return true;

        for (auto& child : graph[curr]) {
            // cout << child << " is a child of " << curr << endl;
            if (visited[child]) continue;
            q.push(child);
            visited[child] = true;
        }

    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    int x, y;

    // vector<vector<int>> graph(n);
    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    cin >> x >> y;

    // print(graph);


    bool xTaller = bfs(graph, x, y, n);
    bool yTaller = bfs(graph, y, x, n);



    if (xTaller) {
        cout << "yes" << endl;
    } else if (yTaller) {
        cout << "no" << endl;
    } else {
        cout << "unknown" << endl;
    }

    return 0;
}