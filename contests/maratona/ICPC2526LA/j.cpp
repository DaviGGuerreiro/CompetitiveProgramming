#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    string s; cin>>s;
    int score = 0;
    string s1 = "ha", s2 = "boooo", s3 = "bravo";
    string x = "", y = "", z = "";
    for(int i = 0 ; i < s.size(); i++){
        if(x.size() < 2){
            x.push_back(s[i]);
        }
        else{
            x[0] = x[1]; x[1] = s[i];
        }

        if(y.size() < 5){
            y.push_back(s[i]);
        }
        else{
            y[0] = y[1]; y[1] = y[2]; y[2] = y[3]; y[3] = y[4]; y[4] = s[i];
        }

        if(z.size() < 5){
            z.push_back(s[i]);
        }
        else{
            z[0] = z[1]; z[1] = z[2]; z[2] = z[3]; z[3] = z[4]; z[4] = s[i];
        }

        if(x == s1){
            score++;
        }
        if(y == s2){
            score--;
        }
        if(z == s3){
            score += 3;
        }
    }
    cout<<score<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}