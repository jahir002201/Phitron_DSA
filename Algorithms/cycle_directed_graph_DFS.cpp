#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
bool pathVisited[100005];
bool cycle;
void dfs(int src){
     visited[src]=true;
     pathVisited[src]=true;
     for(int child:adj_list[src]){
        if(visited[child] && pathVisited[child]){
            cycle=true;
        }
        if(!visited[child]){
            dfs(child);
        }
     }
     pathVisited[src]=false;
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }
    memset(visited,false,sizeof(visited));
    memset(pathVisited,false,sizeof(pathVisited));
    cycle=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
           dfs(i);
        }
    }
    if(cycle){
        cout<<"Cycle Detected"<<endl;
    }else{
        cout<<"No Cycle"<<endl;
    }

    return 0;
}