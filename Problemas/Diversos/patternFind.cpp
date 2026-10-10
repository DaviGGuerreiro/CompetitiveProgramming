#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> LPS(string &t){
	vector<int> p(t.size(), 0);
	for(int i=1, j=0; i<t.size(); i++){
		while(j > 0  && t[j] != t[i]) j = p[j-1];
		if(t[j] == t[i]) j++;
		p[i] = j;
	}
	return p;
}

vector<int> kmp(string &s, string &t){
	vector<int> p = LPS(t), occ;
	for(int i=0, j=0; i<s.size(); i++){
		while( j > 0 && s[i] != t[j]) j = p[j-1];
		if(s[i]==t[j]) j++;
		if(j == t.size()) occ.push_back(i-j+1), j = p[j-1];
	}
	return occ;
}

void solve(){
    string a, b; cin>>a>>b;
    vector<int> resposta = kmp(a, b);
    if(resposta.size() == 0){
        cout<<"Not Found\n";
    }
    else{
        cout<<resposta.size()<<'\n';
        for(auto it: resposta){
            cout<<it+1<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}