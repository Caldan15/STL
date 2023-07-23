#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void addEdge(vector<vector<int>>& aL, int u, int v) {
    aL[u].push_back(v);
    aL[v].push_back(u);
}
vector<int> bfs(const vector<vector<int>>& aL, int s, int end) {
    queue<int> q;
    vector<bool> visit(aL.size(), false);
    vector<int> parent(aL.size(), -1);

    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        for (int neighbor : aL[current]) {
            if (!visit[neighbor]) {
                q.push(neighbor);
                visit[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }
    vector<int> shortestPath;
    int current = end;
    while (current != -1) {
        shortestPath.push_back(current);
        current = parent[current];
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}
int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>> aL(v);
    cout << "Enter the edges " <<endl;
    for (int i = 0; i < e;i++) {
        int x, y;
        cin >> x >> y;
        addEdge(aL, x, y);
    }
    int s, end;
    cout << "Enter the source and destination vertices";
    cin >> s >> end;
    vector<int> shortestPath = bfs(aL, s, end);
    cout << "Shortest path from " << s << " to " << end << ": ";
    for (int v : shortestPath) {
    cout << v << " ";
    }
    cout <<endl;
    return 0;
}
