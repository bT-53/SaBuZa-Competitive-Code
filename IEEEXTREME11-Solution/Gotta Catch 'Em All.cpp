#include<bits/stdc++.h>
using namespace std;

int n,m;
int c[202][202];
int d[202][202];

bool valid(int mid){
    memset(d,0,sizeof d);
    d[1][1] = mid;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(d[i][j]>0){
                if(i<n){
                    d[i+1][j] = max(d[i+1][j],d[i][j]+c[i+1][j]);
                }
                if(j<m){
                    d[i][j+1] = max(d[i][j+1],d[i][j]+c[i][j+1]);
                }
            }
        }
    }
    return d[n][m]>0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&c[i][j]);
        }
    }
    int l=1, r=1000000, mid, ans=1000000;
    while(l<=r){
        mid = (l+r)/2;
        if(valid(mid)){
            ans = min(ans,mid);
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}
