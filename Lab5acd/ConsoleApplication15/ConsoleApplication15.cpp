#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v + 1 << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

void dfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    cout << start + 1 << " ";
    visited[start] = true;

    for (int i = 0; i < graph.size(); i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n = 7;
    vector<vector<int>> graph(n, vector<int>(n));

    graph = {
        {0, 1, 0, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };

    cout << "Обхід графа вшир: " << endl;
    bfs(graph, 0);

    vector<bool> visited(n, false);
    cout << "Обхід графа в глибину: " << endl;
    dfs(graph, 0, visited);

    return 0;
}