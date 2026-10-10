#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
string s;
int n = 1;

int mod_add(int a, int b){
    return (((a % n) + (b % n)) + n) % n;
}

void solve(){
    cin>>s; n = s.size();
    if(s.size() % 2 == 1){ cout<<"NO\n"; return; }
    int a = 0, b = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == 'A') a++;
        else b++;
    }
    if(a % 2 == 1){ cout<<"NO\n"; return; }
    int a_atual = 0, b_atual = 0;
    for(int i = 0 ; i < (s.size()/2); i++){
        if(s[i] == 'A') a_atual++;
        else b_atual++;
    }

    int indice = 1;
    while(a_atual != (a/2) && b_atual != (b/2) && indice <= s.size()){
        if(s[indice - 1] == 'A'){
            a_atual--;
        }
        else{
            b_atual--;
        }

        if(s[mod_add(indice - 1, (s.size()/2))] == 'A'){
            a_atual++;
        }
        else{
            b_atual++;
        }
        indice++;
    }

    if(a_atual == (a/2)){
        cout<<"YES\n";
        cout<<indice<<' '<<((indice + (s.size()/2)) % (n+1))<<'\n';
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}