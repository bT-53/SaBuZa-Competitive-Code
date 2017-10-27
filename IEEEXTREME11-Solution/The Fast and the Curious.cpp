#include <bits/stdc++.h>
#define N 100009
using namespace std;

vector<int> adj[N];
bool vst[N];

int ds[N],dp[N];
int head(int u){
    if(u==ds[u]) return u;
    return ds[u]=head(ds[u]);
}

bool combine(int u,int v){
    u=head(u),v=head(v);
    if(u==v) return false;
    ds[u]=v;
    return true;
}

vector<int> uu,vv;

int par[30][N],lv[N];
void dfs(int u,int p){
    //cout << u << endl;
    par[0][u]=p; lv[u]=1+lv[p];
    for(int v: adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
}

void build(int n){
    for(int i=1;i<=n;i++){
        if(lv[i]==0) dfs(i,0);
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }
}

int lca(int u,int v){
    if(lv[u]<lv[v]) swap(u,v);
    for(int i=0, d=lv[u]-lv[v];i<20;i++, d/=2){
        if(d%2) u=par[i][u];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(par[i][u]!=par[i][v]) u=par[i][u],v=par[i][v];
    }
    return par[0][u];
}
void dfs2(int u,int p){
    vst[u]=true;
    for(int v: adj[u]){
        if(v==p) continue;
        dfs2(v,u);
        dp[u]+=dp[v];
    }
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) ds[i]=i;
    for(int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        if(combine(u,v)){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            uu.push_back(u);
            vv.push_back(v);
        }
    }
    /*for(int i=0;i<uu.size();i++)
        printf("%d %d\n",uu[i],vv[i]);*/
    build(n);
    for(int i=0;i<uu.size();i++){
        int u=uu[i],v=vv[i];
        int l=lca(u,v);
        if(l==0) continue;
        dp[u]++; dp[v]++;
        dp[l]--; dp[par[0][l]]--;
    }
    for(int i=1;i<=n;i++){
        if(!vst[i]) dfs2(i,0);
    }
    //for(int i=1;i<=n;i++) cout << dp[i] << " "; cout << endl;
    for(int i=1;i<=n;i++){
        if(dp[i]==0) printf("%d\n",i);
    }
    return 0;
}
