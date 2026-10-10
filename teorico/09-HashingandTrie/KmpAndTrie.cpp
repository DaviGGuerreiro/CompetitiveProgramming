#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    return 0;
}