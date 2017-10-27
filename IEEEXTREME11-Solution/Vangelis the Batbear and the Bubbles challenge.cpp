#include <bits/stdc++.h>
#define N 100009
using namespace std;

set<int> adj[N];
bool vst[N],ans;

void dfs(int u, int p){
    vst[u]=1;
    for(int v: adj[u]){
        if(v==p) continue;
        if(vst[v]) ans=true;
        else dfs(v,u);
    }
}

void solve(){
    int n,m; scanf("%d%d",&n,&m);
    ans=false;
    while(m--){
        int u,v; scanf("%d%d",&u,&v);
        if(u==v){
            ans=true; continue;
        }
        if(!adj[u].insert(v).second) ans=true;
        if(!adj[v].insert(u).second) ans=true;
    }
    memset(vst,0,sizeof vst);
    for(int i=0;i<n;i++){
        if(vst[i]==0) dfs(i,-1);
    }
    for(int i=0;i<n;i++) adj[i].clear();
    printf("%d\n",(ans?1:0));
}

int main()
{
    int T; scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
