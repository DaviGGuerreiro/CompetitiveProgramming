#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; pair<int, int> destino;
    cin>>n>>destino.first>>destino.second;
    pair<int,int> origem = {(1<<(n-1)), (1<<(n-1))};
    int x = 0;
    int diff;
    while(destino.first != origem.first){
        if(destino.first < origem.first){
            destino.first *= 2;
        }
        else{
            diff = (1<<n) - destino.first;
            destino.first -= diff;
        }
        x++;
    }
    int y = 0;
    while(destino.second != origem.second){
        if(destino.second < origem.second){
            destino.second *= 2;
        }
        else{
            diff = (1<<n) - destino.second;
            destino.second -= diff;
        }
        y++;
    }
    cout<<(max(x,y))<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}