#include <bits/stdc++.h>
using namespace std;
int n,m,c;
char iz[30][30];
int z[2][30][30];
int curtab=0;
set<pair<int,int> > s;
map <set<pair<int,int> >,int > mp;

void showTable(){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
           if (z[curtab][i][j]) printf ("*");
            else printf ("-");
        }
        printf ("\n");
    }

}

int nTab(){
    return !curtab;
}

int liveAround(int r,int c){
    int ret = 0,i,j,nr,nc;
    for (i=-1;i<=1;i++){
        for (j=-1;j<=1;j++){
            if (i==0&&j==0) continue;
            nr = i + r;
            nc = j + c;
            if (nr<0) nr = n-1;
            else if (nr>=n) nr = 0;
            if (nc<0) nc = m-1;
            else if (nc>=m) nc = 0;
            ret += (z[curtab][nr][nc]);
        }
    }
    return ret;
}


void runTable(){
    int i,j,nt,br,bc,nr,nc,liveSum=0;
    nt = nTab();
    s.clear();
    for (i=0;i<n;i++){
        if (i==0) br = n - 1;
        else br = i-1;
        if (i==n-1) nr = 0;
        else nr = i+1;
        for (j=0;j<m;j++){
            if (j==m-1) nc = 0;
            else nc = j + 1;
            bc = j - 2;
            if (bc < 0) bc += m;
            if (j==0){
                liveSum = liveAround(i,j);
            }else{
                liveSum += z[curtab][i][nc] + z[curtab][nr][nc] + z[curtab][br][nc];
                liveSum -= z[curtab][i][bc] + z[curtab][nr][bc] + z[curtab][br][bc];
                liveSum += z[curtab][i][j-1];
                liveSum -= z[curtab][i][j];
            }
            if (z[curtab][i][j]){
                if (liveSum<2 || liveSum>3){
                    z[nt][i][j] = 0;
                }else{
                    z[nt][i][j] = 1;
                    s.insert(make_pair(i,j));
                }
            }else{
                if (liveSum==3){
                    z[nt][i][j] = 1;
                    s.insert(make_pair(i,j));
                }else z[nt][i][j] = 0;
            }

        }
    }
    curtab = 1 - curtab ;
}

int main() {
    int itt,i,j;
    scanf ("%d%d%d",&n,&m,&c);
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            scanf (" %c",&iz[i][j]);
            //z[0][i][j] = (iz[i][j] == '*');
            if (iz[i][j]=='*'){
                s.insert(make_pair(i,j));
                z[0][i][j] = 1;
            }else{
                z[0][i][j] = 0;
            }
        }
    }
    mp[s] = 1;
    for (itt=2;itt<=c+1;itt++){
        runTable();
        if (mp.find(s)!=mp.end()){
            //showTable();
            //printf ("%d\n",itt);
            int loopcnt = itt - mp[s],looprem = (c+1) - itt;
            looprem %= loopcnt;
            for (int ii=1;ii<=looprem;ii++){
                runTable();
            }
            break;
        }
        mp[s] = itt;
    }
    showTable();
    //printf ("x\n");
    return 0;
}
