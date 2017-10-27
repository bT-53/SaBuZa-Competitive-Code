#include<bits/stdc++.h>
using namespace std;

int n, now=0, height;
vector<string> v[500];
string name;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> name >> height;
        v[height].push_back(name);
    }
    for(int i=120; i<=250; i++){
        sort(v[i].begin(),v[i].end());
        for(string t : v[i]){
            cout << t << " ";
        }
        if(v[i].size()>0){
            cout << (now+1) << " " << (now+v[i].size()) << endl;
            now += v[i].size();
        }
    }
    return 0;
}
