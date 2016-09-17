#include <bits/stdc++.h>
using namespace std;

int N;
int nidx=1;
int lazy[400005],ar[400005],st[400005],par[400005],chainPar[40005];
int chainID[40005],chainHead[40005],posInSmt[40005],posInChain[40005],chainSize[40005],chainHeadID[40005],curChainNum=0;
int chainLevel[40005],subTree[40005];
//vector <int> adj0[40005];
map <int,int> hidx;
//vector <int> adj[40005];
bool vst[40005];

struct qry{
    int a,b,c;
}q[40005];
struct node{
    int par,idx,w;
    node (int a,int b){
        idx = a;
        w = b;
    }
    node (int a){
        idx = a;
    }
    bool operator <(node ot)const {
        return subTree[ot.idx]<subTree[idx];
    }
};

vector <node> adj[40005],adj0[40005];

void clearmem(){
    nidx = 1;
    N = 0;

    for (int i=0;i<40005;i++){
        q[i].a = q[i].b = q[i].c = 0;
        lazy[i] = st[i] = par[i] = chainPar[i] = chainID[i] = chainHead[i] = posInSmt[i] = posInChain[i] = 0;
        chainSize[i] = chainHeadID[i] = curChainNum = chainLevel[i] = subTree[i] = 0;
        adj[i].clear();
        adj0[i].clear();
        vst[i] = false;
    }
    hidx.clear();
}

void build(int idx,int l,int r){
    if (l==r){
        st[idx] = ar[l];
        //printf ("%d %d : %d\n",l,r,st[idx]);
        return;
    }
    build(idx*2,l,(l+r)/2);
    build(idx*2+1,(l+r)/2+1,r);
    st[idx] = max(st[idx*2],st[idx*2+1]);
    //printf ("%d %d : %d\n",l,r,st[idx]);
}

void update(int idx,int l,int r,int a,int b,int val){
    if (r<a||l>b){
        return ;
    }
    if (lazy[idx]){
        st[idx] = lazy[idx];
        if (r!=l){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l>=a&&r<=b){
        st[idx] = val;
        if (r!=l){
            lazy[idx*2] = val;
            lazy[idx*2+1] = val;
        }
        return;
    }
    update(idx*2,l,(l+r)/2,a,b,val);
    update(idx*2+1,(l+r)/2+1,r,a,b,val);
    st[idx] = max(st[idx*2],st[idx*2+1]);
}

int query(int idx,int l,int r,int a,int b){
    if (r<a||l>b){
        return -2100000000;
    }
    if (lazy[idx]){
        st[idx] = lazy[idx];
        if (r!=l){
            lazy[idx*2] = lazy[idx];
            lazy[idx*2+1] = lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (l>=a&&r<=b){
        return st[idx];
    }
    int q1,q2;
    q1 = query(idx*2,l,(l+r)/2,a,b);
    q2 = query(idx*2+1,(l+r)/2+1,r,a,b);
    return max(q1,q2);
}

int RebuildTree(int idx,int lvl){
    vst[idx] = true;
    int ret = 1;
    //hidx[idx] = nidx++;
    //printf ("%d %d\n",idx,lvl);
    for (int i=0;i<adj0[idx].size();i++){
    //for (node x:adj0[idx]){
        node x = adj0[idx][i];
        if (!vst[x.idx]){
            par[x.idx] = idx;
            adj[idx].push_back(node(x.idx,x.w));
            //update(1,1,N,x.idx,x.idx,x.w);
            ret += RebuildTree(x.idx,lvl+1);
        }
    }
    subTree[idx] = ret;
    return ret;
}

void buildHLD(int idx, bool isNewChain){
    sort(adj[idx].begin(),adj[idx].end());
    if (isNewChain){
        chainID[idx] = ++curChainNum;
        chainHeadID[chainID[idx]] = idx;
        chainLevel[chainID[idx]] = chainLevel[chainID[par[idx]]] + 1;
    }
    hidx[idx] = nidx++;
    chainID[idx] = curChainNum;
    chainSize[chainID[idx]]++;
    posInChain[idx] = chainSize[chainID[idx]];
    if (adj[idx].size()){
        buildHLD(adj[idx][0].idx,false);
        for (int i=1;i<adj[idx].size();i++){
            buildHLD(adj[idx][i].idx,true);
        }
    }
}

int queryHLD(int u,int v){
    int uchain,vchain,ret=-2100000000;
    uchain = chainID[u];
    vchain = chainID[v];
    while (uchain!=vchain){
        if (chainLevel[uchain]>chainLevel[vchain]){
            swap(u,v);
            uchain = chainID[u];
            vchain = chainID[v];
        }
        ret = max(ret,query(1,1,N,hidx[chainHeadID[vchain]],hidx[v]));
        v = par[chainHeadID[vchain]];
        uchain = chainID[u];
        vchain = chainID[v];
        //printf ("%d %d : %d %d -> %d %d %d\n",u,v,hidx[u],hidx[v],chainHeadID[vchain],hidx[chainHeadID[vchain]],ret);
    }

    if (posInChain[u]>posInChain[v]) swap(u,v);
    //printf ("%d ==> %d %d : %d %d \n",ret,u,v,hidx[u],hidx[v]);
    if (u!=v) ret = max(ret,query(1,1,N,min(hidx[u],hidx[v])+1,max(hidx[u],hidx[v])));
    //printf ("==> %d -> %d %d\n",ret,query(1,1,N,min(hidx[u],hidx[v]),max(hidx[u],hidx[v])),query(1,1,N,min(hidx[u],hidx[v]),min(hidx[u],hidx[v])));
    //else return 0;
    //if (u==11&&v==13){
        //printf ("%d %d : %d %d : %d %d \n",uchain,vchain,hidx[u],hidx[v],posInChain[u],posInChain[v]);
    //}
    return max(0,ret);
}

/*
long long queryHLD(int u,int v){
    int uchain,vchain,ret=0;
    uchain = chainID[u];
    vchain = chainID[v];
    while (uchain!=vchain){
        ret += query(1,1,N,posInSmt[chainHead[u]],u);
        u = par[chainHead[uchain]];
    }
    ret += query(1,1,N,posInSmt[u],posInSmt[v]);
    return ret;
}

int queryLCA(int A,int B){
    //int lca = LCA(A,B);
    //return max(queryHLD(A,lca),queryHLD(B,lca));

}*/


int main(){
int TC;
scanf ("%d",&TC);
for (int tc=1;tc<=TC;tc++){
    clearmem();
    scanf ("%d",&N);
    for (int i=1;i<N;i++){
        int a,b,c;
        scanf ("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
        adj0[q[i].a].push_back(node(q[i].b,q[i].c));
        adj0[q[i].b].push_back(node(q[i].a,q[i].c));
    }
    /*adj0[1].push_back(2);
    adj0[1].push_back(3);
    adj0[1].push_back(4);
    adj0[2].push_back(5);
    adj0[4].push_back(6);
    adj0[5].push_back(7);
    adj0[5].push_back(8);
    adj0[7].push_back(9);
    adj0[8].push_back(10);
    adj0[8].push_back(11);
    adj0[10].push_back(12);
    adj0[11].push_back(13);
    adj0[14].push_back(11);
    for (int i=1;i<=15;i++){
        for (int x:adj0[i]){
            adj0[x].push_back(i);
        }
    }*/

    RebuildTree(1,1);
    //build(1,1,N);
    buildHLD(1,true);
    for (int i=1;i<N;i++){
        int cid = max(hidx[q[i].a],hidx[q[i].b]);
        ar[cid] = q[i].c;
        //printf ("%d : %d %d\n",i,cid,ar[cid]);
    }
    build(1,1,N);
    /*
    for (int i=1;i<=N;i++){

        printf ("-----> %d : %d %d\n",i,ar[i],query(1,1,N,i,i));

    }*/
    /*
    for (int i=1;i<=15;i++){
        printf ("%d : %d %d %d %d %d %d %d\n",i,chainID[i],chainHeadID[chainID[i]],chainSize[chainID[i]],chainLevel[chainID[i]],subTree[i],posInChain[i],par[i]);
    }
    printf ("%lld\n",curChainNum);
    */
    while (1){
        char cmd[20];
        int a,b;
        scanf ("%s",cmd);
        if (cmd[0]=='D') break;
        else if (cmd[0]=='C'){
            scanf ("%d%d",&a,&b);
            int cid = max(hidx[q[a].b],hidx[q[a].a]);
            update(1,1,N,cid,cid,b);
            //printf ("%d %d : %d %d\n",a,b,q[a].b,hidx[q[a].b]);
        }else if (cmd[0]=='Q'){
            scanf ("%d%d",&a,&b);
            printf ("%d\n",queryHLD(a,b));
            //printf ("->%d\n",query(1,1,N,a,b));
        }else if (cmd[0]=='A'){
            printf ("-----------------\n");
            for (int i=1;i<=N;i++){
                for (int j=1;j<=N;j++){
                    printf ("%d %d : %d\n",i,j,queryHLD(i,j));
                }
            }
            printf ("-----------------\n");
        }else if (cmd[0]=='q'){
            scanf ("%d%d",&a,&b);
            printf ("%d %d : %d\n",hidx[a],hidx[b],query(1,1,N,hidx[a],hidx[b]));
        }else if (cmd[0]=='c'){
            for (int i=1;i<=N;i++){
                printf ("%d : %d %d\n",i,chainID[i],chainHeadID[chainID[i]]);
            }
        }
    }
    //printf ("\n");
}
return 0;
}
