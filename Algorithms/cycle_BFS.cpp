#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
int parent[100005];
bool cycle;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;  

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par]) {
            if (visited[child] && parent[par] != child) {
                cycle = true;
                return;
            }

            if (!visited[child]) {
                visited[child] = true;
                parent[child] = par;  
                q.push(child);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
            if (cycle) break;
        }
    }

    if (cycle) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle" << endl;
    }

    return 0;
}
