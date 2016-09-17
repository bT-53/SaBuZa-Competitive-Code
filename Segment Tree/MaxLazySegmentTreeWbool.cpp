#include <bits/stdc++.h>
using namespace std;

#define N 4000005

bool isLazy[N];
long long st[N],ar[N],lazy[N];

void build(int idx,int l,int r){
    if (r==l){
        st[idx] = ar[l];
        return;
    }
    build (idx*2,l,(l+r)/2);
    build (idx*2+1,(l+r)/2+1,r);
    st[idx] = max(st[idx*2],st[idx*2+1]);
}

void update(int idx,int l,int r,int a,int b,long long val){
    if (isLazy[idx]){
        st[idx] = lazy[idx];
        if (r!=l){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
            isLazy[idx*2] = true;
            isLazy[idx*2+1] = true;
        }
        lazy[idx] = 0;
        isLazy[idx] = false;
    }
    if (r<a||l>b)
        return ;

    if (l>=a&&r<=b){
        st[idx] = val;
        if (r!=l){
            lazy[idx*2] = val;
            lazy[idx*2+1] = val;
            isLazy[idx*2] = true;
            isLazy[idx*2+1] = true;
        }
        return;
    }
    update(idx*2,l,(l+r)/2,a,b,val);
    update(idx*2+1,(l+r)/2+1,r,a,b,val);
    st[idx] = max(st[idx*2],st[idx*2+1]);
}

long long query(int idx,int l,int r,int a,int b){
    if (r<a||l>b) return -INFINITY;
    if (isLazy[idx]){
        st[idx] = lazy[idx];
        if (r!=l){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
            isLazy[idx*2] = true;
            isLazy[idx*2+1] = true;
        }
        lazy[idx] = 0;
        isLazy[idx] = false;
    }
    if (l>=a&&r<=b) return st[idx];
    long long q1,q2;
    q1 = query(idx*2,l,(l+r)/2,a,b);
    q2 = query(idx*2+1,(l+r)/2+1,r,a,b);
    return max(q1,q2);
}

int main(){

    return 0;
}
