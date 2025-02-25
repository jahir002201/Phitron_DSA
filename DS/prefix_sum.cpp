#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        
        L--; R--;
        
        long long int sum = 0;
        if (L == 0) {
            sum = prefix_sum[R];
        } else {
            sum = prefix_sum[R] - prefix_sum[L - 1];
        }
        
        cout << sum << endl;
    }

    return 0;
}