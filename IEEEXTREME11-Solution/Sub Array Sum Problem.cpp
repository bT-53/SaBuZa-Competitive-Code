#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n[10],l[10],r[10];
vector<ll> a,qs;

int main() {
    int d; scanf("%d",&d);
    int t=1;
    for(int i=0;i<d;i++){
        scanf("%d",n+i); t*=n[i];
    }
    for(int i=0;i<t;i++){
        ll x; scanf("%lld",&x);
        a.push_back(x);
        qs.push_back(x);
        deque<int> vc;
        int tmp=i;
        for(int k=d-1;k>=0;k--){
            vc.push_front(tmp%n[k]);
            tmp/=n[k];
        }
        for(int j=0;j+1<(1<<d);j++){
            int cnt=0,index=0,tt;
            for(int k=0;k<d;k++){
                if((1<<k)&j) tt=vc[k];
                else tt=vc[k]-1,cnt++;
                if(tt==-1) break;
                index=index*n[k]+tt;
                tmp/=n[k];
            }
            if(tt==-1) continue;
            //cout << i << " " << j << " " << index << " "<< cnt << endl;
            if(cnt%2==0) qs[i]-=qs[index];
            else qs[i]+=qs[index];
        }
    }
    //for(int i=0;i<t;i++) cout << qs[i] << " "; cout << endl;
    int q; scanf("%d",&q);
    while(q--){
        for(int i=0;i<d;i++) scanf("%d",l+i), l[i]--;
        for(int i=0;i<d;i++) scanf("%d",r+i), r[i]--;
        ll ans=0;
        for(int i=0;i<(1<<d);i++){
            int cnt=0,index=0;
            for(int j=0;j<d;j++){
                int tmp;
                if(i&(1<<j)) tmp=r[j];
                else tmp=l[j]-1,cnt++;
                if(tmp==-1){
                    index=-1; break;
                }
                index=index*n[j]+tmp;
            }
            if(index==-1) continue;
            if(cnt%2) ans-=qs[index];
            else ans+=qs[index];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
