#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n + 1);
    for(int i = 1 ; i<=n; i++){
        cin>>vec[i];
    }
    int l = 1, r = n;
    bool resposta = true;
    bool estado = false;
    int valor = -1;
    while(r > l){
        if(!estado){
            if(vec[l] != l){
                if(valor != -1){
                    if(vec[l] == valor && vec[r] == l){
                        l++; r--; valor = -1; resposta = true; continue;
                    }
                    else break;
                }
                valor = l;
                resposta = false;
                estado = !estado;
            }
            else l++;
        }
        else{
            if(vec[r] != r){
                if(valor != -1){
                    if(vec[r] == valor && vec[l] == r){
                        l++; r--; valor = -1; resposta = true; continue;
                    }
                    else break;
                }
                resposta = false;
                valor = r;
                estado = !estado;
            }
            else r--;
        }
    }
    if(resposta) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}