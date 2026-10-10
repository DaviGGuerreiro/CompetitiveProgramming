#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<int> a (n), b (n);
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n; i++){
        cin>>b[i];
    }
    int uz = 0, zz = 0, uu = 0, zu = 0;
    for(int i = 0;  i<n; i++){
        if(a[i] == 0 && b[i] == 0) zz++;
        else if(a[i] == 0 && b[i] == 1) zu++;
        else if(a[i] == 1 && b[i] == 0) uz++;
        else uu++;
    }
    if(uz == 0 && zu == 0) cout<<"0\n";
    else if(uz == 0 && uu == 0) cout<<"-1\n";
    else if(uz == 0 && zz == 0) cout<<"-1\n";
    else if((uz == 0 && zz != 0) || (uz != 0 && uz % 2 == 0)) cout<<"2\n";
    else cout<<"1\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}