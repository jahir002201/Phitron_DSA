#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b, w, k, z;
ll d[100005], p[100005];
vector<pair<int, ll>> adj[100005];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

void f(ll i) {
    if (i != 1) f(p[i]);
    cout << i << ' ';
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    fill(d, d + n + 1, LLONG_MAX);
    d[1] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        auto par = q.top();
        q.pop();
        ll par_dis = par.first;
        int par_node = par.second;

        if (par_dis > d[par_node]) continue;

        for (auto& child : adj[par_node]) {
            int child_node = child.first;
            ll weight = child.second;

            if (par_dis + weight < d[child_node]) {
                d[child_node] = par_dis + weight;
                p[child_node] = par_node;
                q.push({d[child_node], child_node});
            }
        }
    }

    if (d[n] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }

    f(n);
    return 0;
}