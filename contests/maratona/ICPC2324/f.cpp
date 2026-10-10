#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll d, c, r; cin>>d>>c>>r;
    int quantidade = 0;
    vector<int> cansa (c,0);
    vector<int> recupera (r, 0);
    int i1 = 0, i2 = 0;
    for(int i = 0; i<c; i++){
        cin>>cansa[i];
    }
    for(int i = 0 ; i<r; i++){
        cin>>recupera[i];
    }

    while(i1 != c || i2 != r){
        if(i2 == r && cansa[i1] > d) break;

        if(i1 != c){
            if(d < cansa[i1] && i2 == r) break;
            if(d < cansa[i1]){
                d += recupera[i2]; i2++; quantidade++;
            }
            else{
                d -= cansa[i1]; i1++; quantidade++;
            }
        }
        else{
            i2++; quantidade++;
        }
    }
    cout<<quantidade<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}