#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
vector<int> ordem;

ll parte(ll n, ll c, int soma){
    ll aux = 0;
    int aux2;
    if(n % 2 == 1){

    }
    else{
        if(n/2 >= c){

        }
        ordem.push_back(n/2);
        ordem.push_back((n/2)+1);
        c -= 2;
        aux += 1;

    }
}

void solve(){
    ll n, c; cin>>n>>c;
    ordem = vector<int> (c);
    ll r = parte(0, c, 0);
    cout<<r<<'\n';
    for(auto it : ordem){
        cout<<it<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}