#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int aux, sobra = 0;
map<int, bool> mapa;

void solve(){
    int n, k; cin>>n>>k;
    priority_queue<int> pq;
    for(int i = 0; i<n; i++){
        cin>>aux;
        if(!mapa[aux]) pq.push(aux);
        else sobra++;
        mapa[aux] = true;
    }
    for(int i = 0 ; i <= ((2e5)+5); i++){
        if(!mapa[i]){
            if(k > 0){
                if(sobra > 0){
                    sobra--;
                }
                else{
                    if(!pq.empty()){
                        aux = pq.top();
                        pq.pop();
                        if(aux > i){
                            mapa[aux] = false;
                        }
                        else{
                            cout<<i<<'\n';
                            return;
                        }
                    }
                    else{
                        cout<<i<<'\n';
                        return;
                    }
                }
                k--;
            }
            else{
                cout<<i<<'\n';
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}