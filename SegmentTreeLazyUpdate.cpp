#include <bits/stdc++.h>

using namespace std;

int d[100005];
int N,K;

class segment{
    int st[400005],lazy[400005];
    public :
    void build (int idx,int l ,int r){
        if (r-l<=1){
            st[idx] = d[l];
            return;
        }
        int mid = (l+r)/2;
        build (idx*2,l,mid);
        build (idx*2+1,mid,r);
        st[idx] = st[idx*2] + st[idx*2+1];
    }
    int query(int idx,int l,int r,int a,int b){
        if (l>=b||r<=a) return 0;
        if (lazy[idx]!=0){
            st[idx] += (b-a+1)*lazy[idx];
            if (r-l>1){
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (l>=a&&r<=b) return st[idx];
        int mid = (l+r)/2;
        return query (idx*2,l,mid,a,b) + query(idx*2+1,mid,r,a,b);
    }

    void update (int idx,int l,int r,int a,int b ,int val ){
        if (l>=b||r<=a) return ;
        if (lazy[idx] != 0){
            st[idx] += (b-a+1)*lazy[idx];
            if (r-l>1){
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (r-l<=1){
            st[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        update (idx*2,l,mid,a,b,val);
        update (idx*2+1,mid,r,a,b,val);
        st[idx] = st[idx*2] + st[idx*2+1];
    }
}s;

int main(){
    int cmd,a,b,k;
    scanf ("%d",&N);
    for (int i=0;i<N;i++)
        scanf ("%d",&d[i]);
    s.build (1,0,N);
    do{
        scanf ("%d",&cmd);
        if (cmd==0) break;
        scanf ("%d%d",&a,&b);
        a--;
        if (cmd==1){
            scanf ("%d",&k);
            s.update (1,0,N,a,b,k);
        }else cout << s.query(1,0,N,a,b) << endl;
    }while (cmd!=0);

return 0;
}
