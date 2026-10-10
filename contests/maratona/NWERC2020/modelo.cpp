#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;

void solve(){
    ld n, d;
    ld x, y;
    cin>>n>>d>>x>>y;
    ld r1 = n * x;
    ld r2 = d * y;
    if(n == d){
        cout<<"impossible"<<'\n'; return;
    }
    ld r3 = (r1 - r2)/(n-d);
    if(r3 + eps < 0.0 ||  r3 - eps > 100.0){
        cout<<"impossible"<<'\n';
    }
    else{
        cout<<fixed<<setprecision(7)<<r3<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}