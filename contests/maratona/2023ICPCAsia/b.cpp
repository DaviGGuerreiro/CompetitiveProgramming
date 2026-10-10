#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int t1, t2; cin>>t1>>t2;
    string s1, s2; cin>>s1>>s2;
    ll n1, d1;
    n1 = stoi(s1);
    d1 = pow(10ll, s1.size());
    ll comum = gcd(n1, d1);
    while(comum != 1){
        n1 /= comum; d1 /= comum;
        comum = gcd(n1, d1);
    }
    ll n2, d2 = 1;
    n2 = stoi(s2);
    d2 = pow(10ll, s2.size()); d2 -=1;
    d2 *= pow(10ll, s1.size());
    comum = gcd(n2, d2);
    while(comum != 1){
        n2 /= comum; d2 /= comum;
        comum = gcd(n2, d2);
    }
    ll n3, d3;
    n3 = (n1 * d2) + (n2 * d1);
    d3 = d1 * d2;
    comum = gcd(n3, d3);
    while(comum != 1){
        n3 /= comum; d3 /= comum;
        comum = gcd(n3, d3);
    }
    cout<<n3<<' '<<d3<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}