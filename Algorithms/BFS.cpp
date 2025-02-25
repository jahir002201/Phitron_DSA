#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int parent[1005];
int level[1005];

void bfs(int src, int des)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }

    if (vis[des])
    {
        int x = des;
        vector<int> path;
        
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }

        reverse(path.begin(), path.end());

        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path from " << src << " to " << des << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src, des;
    cin >> src >> des;

    memset(vis, false, sizeof(vis));
    bfs(src, des);

    return 0;
}