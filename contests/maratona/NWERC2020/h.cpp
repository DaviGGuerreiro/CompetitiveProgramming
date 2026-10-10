#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int index = (n-1)/2;
    int l = index - 1, r = index + 1;
    bool direcao = true;
    cout<<vec[index]<<' ';
    while(l != -1 || r != n){
        if(direcao){
            cout<<vec[r]<<' ';
            r++;
        }
        else{
            cout<<vec[l]<<' ';
            l--;
        }
        direcao = !direcao;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}