#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MAXN = 2026;
ld dp[MAXN + 1][MAXN + 1];

// a, b; a -> quantas o album tem, b -> quantas eu tenho?

void solve(){
    int n; ld p; cin>>n>>p; p = p/100.0;
    for(int i = MAXN; i >= n; i--){
        for(int j = i-1; j >= 0; j--){
            if(i == 2026){
                dp[i][j] = ((2026.0)/(2026.0 - j)) + dp[i][j+1];
            }
            else{
                ld denominador = (1.0 - ((1.0 - p)*((ld)j/(ld)i)));
                ld t1 = 1.0 + (p*(((ld)i + 1.0 - (ld)j)/((ld)i + 1.0)) * dp[i+1][j+1]);
                ld t2 = p * ((ld)j/((ld)(i)+1)) * dp[i+1][j]; 
                ld t3 = (1.0 - p) * (((ld)i - (ld)j)/((ld)i)) * dp[i][j+1];
                dp[i][j] = (t1 + t2 + t3)/denominador;
            }
        }
    }
    cout<<fixed<<setprecision(12)<<dp[n][0]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}