#include <bits/stdc++.h>
using namespace std;
long long st[400005],lazy[400005];

long long query(int idx,int l,int r,int a,int b){
    if (r<a||l>b) return 0;
    if (lazy[idx]){
        st[idx] += lazy[idx] * (r-l+1);
        if (r!=l){
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l>=a&&r<=b){
        return st[idx];

    }
    long long q1,q2;
    q1 = query(idx*2,l,(l+r)/2,a,b);
    q2 = query(idx*2+1,(l+r)/2+1,r,a,b);
    return q1 + q2;

}

void update(int idx,int l,int r,int a,int b,int val){
    if (r<a||l>b) return;
    if (lazy[idx]){
        st[idx] += (r-l+1)*lazy[idx];
        if (r!=l){
            lazy[idx*2] += lazy[idx];
            lazy[idx*2+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l>=a&&r<=b){
        st[idx] += (r-l+1)*val;
        if (r!=l){
            lazy[idx*2] += val;
            lazy[idx*2+1] += val;
        }
        return;
    }
    update(idx*2,l,(l+r)/2,a,b,val);
    update(idx*2+1,(l+r)/2+1,r,a,b,val);
    st[idx] = st[idx*2] + st[idx*2+1];


}

int main(){


return 0;
}
