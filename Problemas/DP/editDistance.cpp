#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
vector<vector<ll>> dp;
string n, m;

//n, m, best nos ultimos indices, se indice negativo return -, se existe dp return dp, se igual dp = 1 + best (dois indices --), se não dp = max(best(i-1,j), best(i,j-1));

void solve(){
    cin>>n>>m;
    dp = vector<vector<ll>> (n.size() + 1, vector<ll> (m.size() + 1, 0));
    for(int i = 1; i <= n.size(); i++) dp[i][0] = i;
    for(int j = 1; j <= m.size(); j++) dp[0][j] = j;
    for(int i = 1; i <= n.size(); i++){
        for(int j = 1; j <= m.size(); j++){
            if(n[i-1] == m[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                ll minimo = dp[i-1][j] + 1;
                minimo = min(minimo, dp[i][j-1] + 1);
                minimo = min(minimo, dp[i-1][j-1] + 1);
                dp[i][j] = minimo;
            }
        }
    }
    cout<<dp[n.size()][m.size()]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}