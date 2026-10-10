#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> vec;

bool func(int mid){
    bool flg1, flg2;
    int aux;
    vector<int> vec_1 (mid), vec_2(mid);
    for(int i = 0; i < n - mid; i++){
        flg1 = true;
        map<int,int> mapa1;
        for(int j = 0; j < mid; j++){
            vec_1[j] = vec[i+j];
            if(mapa1[vec_1[j]] != 0){
                flg1 = false;  break;
            }
            mapa1[vec_1[j]]++;
        }
        for
        if(!flg1) continue;
        set<int> set2;
        for(int j = i + mid; j < n-mid; j++){
            flg2 = true;
            for(int k = 0; k < mid; k++){

            }
            if(!flg2) continue;
        }
        if(!flg2) break;
        aux = *set1.begin();
        if(aux + mid == *set2.begin()) return true;
    }
    return false;
}

void solve(){
    cin>>n;
    vec = vector<int> (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    int l = 1, r = n/2, mid;
    int resposta = 0;
    while(r >= l){
        mid = l + ((r-l)/2);
        if(func(mid)){
            resposta = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}