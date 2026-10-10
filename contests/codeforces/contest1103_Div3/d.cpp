#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k; cin>>n>>k;
    vector<int> vec (n);
    vector<int> v (n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        v[vec[i]]++;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(),vec.end()), vec.end());
    int tamanho = vec.size();
    if(v[vec[tamanho-1]] % 2 == 0){
        cout<<"YES"<<'\n';
        return;
    }
    for(int i = tamanho-2; i>=0; i--){
        if(vec[i+1] - vec[i] <= k){
            cout<<"YES"<<'\n';
            return;
        }
        else{
            if(v[vec[i]] % 2 == 0){
                cout<<"YES"<<'\n';
                return;
            }
        }
    }
    cout<<"NO"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}