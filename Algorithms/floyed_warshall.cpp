#include<bits/stdc++.h>
using namespace std;
int adj_mat[1000][1000];
int n,e;
void floydWarshall(){
    for(int k=0;k<n;k++){
       for(int i=0;i<n;i++){
        if(adj_mat[i][k]==INT_MAX) continue;
        for(int j=0;j<n;j++){
            if(adj_mat[k][j]!=INT_MAX && adj_mat[i][k]+adj_mat[k][j]<adj_mat[i][j]){
              adj_mat[i][j]=min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j]);
            }
        }
       }
    }
}
int main(){
    cin>>n>>e;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj_mat[i][j]=INT_MAX;
            if(i==j) adj_mat[i][j]=0;
        }
    }
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj_mat[a][b]=c;
    }
    floydWarshall();
    bool cycle=false;
    for (int i = 0; i < n; i++) {
        if (adj_mat[i][i] < 0) {
            cycle = true;
            break;
        }
    }
    if (cycle) {
        cout << "Negative cycle detected" << endl;
    } else {
        cout << "Shortest paths between all pairs:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj_mat[i][j] == INT_MAX)
                    cout << "src->" << i << " dis->" << j << " weight: INF, ";
                else
                    cout << "src->" << i << " dis->" << j << " weight: " << adj_mat[i][j] << ", ";
            }
            cout << endl;
        }
    }
    return 0;
}