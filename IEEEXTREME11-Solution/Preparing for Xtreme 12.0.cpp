#include <bits/stdc++.h>
using namespace std;

char s[100009];
map<string,int> mp;
int a[109],t[109];
int dp[2][2000000];

int main()
{
    int cnt=0; int n=0;
    while(fgets(s,100000,stdin)!=NULL){
        char * pch;
        //if(s[0]=='-') break;
        pch=strtok (s," \n"); n++;
        sscanf(pch,"%d",t+n);
        //cout << t[n] << "-";
        pch = strtok (NULL, " \n");
        while(pch != NULL)
        {
            if(mp.find(pch)==mp.end()) mp[pch] = cnt++;
            //cout << pch << "-";
            a[n]|=(1<<mp[pch]);
            pch = strtok (NULL, " \n");
        }//cout << endl;
    }
    //for(int i=1;i<=n;i++){ cout << t[i] << " " << a[i] << endl;}
    for(int i=1;i<(1<<cnt);i++) dp[0][i]=dp[1][i]=1000000000;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<cnt);j++)
            dp[i%2][j]=dp[(i+1)%2][j];
        for(int j=0;j<(1<<cnt);j++){
            dp[i%2][j|a[i]]=min(dp[i%2][j|a[i]],dp[(i+1)%2][j]+t[i]);
            //cout << (j|a[i]) << " " << dp[(i+1)%2][j|a[i]] << " " << dp[(i+1)%2][j]+t[i] << " " << dp[i%2][j|a[i]]<< endl;
        }
        //for(int j=0;j<(1<<cnt);j++) cout << dp[i%2][j] << " "; cout << endl;
    }
    printf("%d",dp[n%2][(1<<cnt)-1]);
    return 0;
}
