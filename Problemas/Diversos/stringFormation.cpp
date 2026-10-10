#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s; cin>>s;
    deque<char> palavra;
    for(auto it: s){
        palavra.push_front(it);
    }
    int q; cin>>q;
    int tipo, tipo2;
    bool reverse = false;
    char letra;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            reverse = !reverse;
        }
        else{
            cin>>tipo2>>letra;
            if(tipo2 == 1){
                if(reverse){
                    palavra.push_front(letra);
                }
                else{
                    palavra.push_back(letra);
                }
            }
            else{
                if(reverse){
                    palavra.push_back(letra);
                }
                else{
                    palavra.push_front(letra);
                }
            }
        }
    }
    if(!reverse){
        while(!palavra.empty()){
            letra = palavra.back();
            palavra.pop_back();
            cout<<letra;
        }
    }
    else{
        while(!palavra.empty()){
            letra = palavra.front();
            palavra.pop_front();
            cout<<letra;
        }
    }
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}