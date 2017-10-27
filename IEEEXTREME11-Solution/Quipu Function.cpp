#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pp[10],dd[10];

int main()
{
    int t; ll a,b; scanf("%d%lld%lld",&t,&a,&b);
    ll ans=0;
    for(int i=0;i<t;i++) scanf("%lld",pp+i);
    for(ll i=1;i<=1000000ll;i++){
        ans+=b/i-(a-1)/i;
        ll j=max(a-1,i*1000000ll);
        if(j<b) ans+=b/i-j/i;
    }
    //printf("%lld\n",ans);
    for(int i=0;i<t;i++){
        ll p=pp[i],res=ans;
        ll l=(a+p-1)/p,r=b/p;
        for(ll k=1;k<=1000000ll;k++){
            res-=r/k-(l-1)/k;
            ll j=max(l-1,k*1000000ll);
            if(j<r) res-=r/k-j/k;
        }
        printf("%lld\n",res);
    }
    return 0;
}
