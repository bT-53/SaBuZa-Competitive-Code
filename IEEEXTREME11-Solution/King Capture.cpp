#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[109];
int dp[109][109];

int GetBlack() {
    int black_king_node;
    cin >> black_king_node;
    return black_king_node;
}

void SetWhite(int node) {
    cout << node << endl;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dp[i][j]=1000;
    }
    for(int i=1;i<=n;i++) dp[i][i]=0, adj[i].push_back(i);
    for(int k=0;k<n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]<1000) continue;
                int mx=0;
                for(int v: adj[j]){
                    int mn=1000;
                    for(int u: adj[i]){
                        mn=min(mn,1+dp[u][v]);
                    }
                    mx=max(mx,mn);
                }
                dp[i][j]=mx;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%2d ",dp[i][j]);
        }printf("\n");
    }*/

    int mn=1000,x=0;
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=1;j<=n;j++){
            mx=max(mx,dp[i][j]);
        }
        if(mx<mn){
            mn=mx; x=i;
        }
    }
    SetWhite(x);
    int y = GetBlack();
    while(x!=y){
        mn=1000;
        for(int u: adj[x]){
            int mx=0;
            if(dp[u][y]<mn){
                mn=dp[u][y]; x=u;
            }
            //cout << u << "-" << mx << endl;
        }
        SetWhite(x);
        if(x==y) return 0;
        y=GetBlack();
    }
    return 0;
}
