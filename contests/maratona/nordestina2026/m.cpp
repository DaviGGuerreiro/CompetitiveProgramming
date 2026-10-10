#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    string a, b; cin>>a>>b;
    ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for(int i = 0; i<n;i++){
        if(a[i] == 'R'){
            if(b[i] == 'R'){
                t1++;
            }
            else{
                t3++;
            }
        }
        else{
            if(b[i] == 'G'){
                t2++;
            }
            else{
                t4++;
            }
        }
    }
    int dif = abs(t3 - t4);
    ll p1 = (dif+1)/2, p2 = dif/2; p1 *= p1; p2 *= p2;
    ll resposta = t1 * t1 + t2 * t2; resposta -= (p1 + p2);
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}