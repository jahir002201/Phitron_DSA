#include<bits/stdc++.h>
using namespace std;
int parent[100005];
int group_size[100005];
int dsu_find(int node){
    if(parent[node]==-1) return node;
    int leader=dsu_find(parent[node]);
    parent[node]=leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2){
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
    if(group_size[leaderA]>group_size[leaderB]){
        parent[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }else{
        parent[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    bool cycle=false;
    memset(parent,-1,sizeof(parent));
    memset(group_size,1,sizeof(group_size));
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA==leaderB){
          cycle=true;
        }else{
            dsu_union_by_size(a,b);
        } 
    }
    if(cycle){
        cout<<"Cycle Detected."<<endl;
    }else{
        cout<<"No Cycle."<<endl;
    }
    return 0;
}