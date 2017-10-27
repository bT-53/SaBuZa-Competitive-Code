#include <bits/stdc++.h>
#define N 1000009
#define mod 1000000007ll
#define mod2 500000003ll
using namespace std;
typedef long long ll;

ll fac[N]={1};
ll cnt2[N],fcnt2[N];

ll pow(ll a,ll n,ll m){
    ll ret = 1, q=a;
    for(ll i=1;i<=n;i+=i){
        if(n&i) ret=ret*q%m;
        q=q*q%m;
    }
    return ret;
}

ll modinv(ll a, ll p){
    return pow(a,p-2,p);
}

int main()
{
    int t; scanf("%d",&t);
    for(int i=1;i<=1000000;i++)
        fac[i]=i*fac[i-1]%mod2;
    for(int i=2;i<=1000000;i++){
        if(i%2==0) cnt2[i]=cnt2[i/2]+1;
        fcnt2[i]=fcnt2[i-1]+cnt2[i];
    }
    while(t--){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        int r2=0,rx=0;
        if(fcnt2[b]==fcnt2[c]+fcnt2[b-c]) r2=1;
        rx=fac[b]*modinv(fac[c],mod2)%mod2*modinv(fac[b-c],mod2)%mod2;
        if(rx%2!=r2) rx+=mod2;
        //cout << rx << endl;
        printf("%lld\n",pow(a,rx,mod));
    }
    return 0;
}
