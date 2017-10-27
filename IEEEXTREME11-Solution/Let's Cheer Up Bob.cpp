#include <bits/stdc++.h>

using namespace std;

int z[5][5];
pair<int,int> pw;
int maxlvl=0,anstimes=-1;
pair<int,int> pin[100],myp[100];
vector <pair<int,int> > anslist,tmplist;

bool checkverti(int c){
    int s = 0;
    for (int i=1;i<=3;i++)
        s += z[i][c];
    return (s==3);
}

bool checkhori(int r){
    int s = 0;
    for (int i=1;i<=3;i++)
        s += z[r][i];
    return (s==3);
}

bool mypVerti(int c){
    int s = 0;
    for (int i=1;i<=3;i++)
        s += z[i][c];
    return (s==-3);
}

bool mypHori(int r){
    int s = 0;
    for (int i=1;i<=3;i++)
        s += z[r][i];
    return (s==-3);
}

bool checkdiag(){
    if (z[1][1] + z[2][2] + z[3][3] == 3){
        return true;
    }
    if (z[1][3] + z[2][2] + z[3][1] == 3){
        return true;
    }
    return false;
}

bool mypDiag(){
    if (z[1][1] + z[2][2] + z[3][3] == -3){
        return true;
    }
    if (z[1][3] + z[2][2] + z[3][1] == -3){
        return true;
    }
    return false;
}

bool check(){
    for (int i=1;i<=3;i++){
        if (checkverti(i)) return true;
        if (checkhori(i)) return true;
    }
    if (checkdiag()) return true;
    return false;
}

bool mypFin(){
    for (int i=1;i<=3;i++){
        if (mypVerti(i)) return true;
        if (mypHori(i)) return true;
    }
    if (mypDiag()) return true;
    return false;
}

void cheer(){
    int j=0,donetimes=0;
    tmplist.clear();
    memset(z,0,sizeof z);
    for (int i=0;i<9;i++,j++){
        while (z[pin[i].first][pin[i].second]==-1) i++;
        z[pin[i].first][pin[i].second] = 1;
        donetimes++;
        if (check()){
            if (anstimes==-1 || anstimes > donetimes){
                anstimes = donetimes;
                anslist = tmplist;
            }
        }
        if (z[myp[j].first][myp[j].second]==1) return ;
        z[myp[j].first][myp[j].second] = -1;
        tmplist.push_back(make_pair(myp[j].first,myp[j].second));
        if (mypFin()) return;
    }
}

int main() {
    int ii=0,iii=0,r,c;
    memset(z,0,sizeof z);
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            myp[iii++] = make_pair(i,j);
        }
    }
    while (scanf ("%d %d",&r,&c)==2){
        //printf ("-> %d %d \n",r,c);
        pin[ii++] = make_pair(r,c);

    }
    do{
        cheer();
    }while (next_permutation(myp,myp+ii));
    for (pair<int,int> px : anslist)
        printf ("%d %d\n",px.first,px.second);


    return 0;
}
