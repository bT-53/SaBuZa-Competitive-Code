#include <bits/stdc++.h>
using namespace std;

vector <long long> prime;

int main(){
    prime.push_back(2);
    for (int i=3;i<=97;i+=2){
        bool chk = true;
        for (int j=1;j<prime.size();j++){
            if (i%prime[j]==0){
                chk = false;
                break;
            }
        }
        if (chk) prime.push_back(i);
    }
    for (long long x:prime){
        printf ("%lld\n",x);
    }
return 0;
}
