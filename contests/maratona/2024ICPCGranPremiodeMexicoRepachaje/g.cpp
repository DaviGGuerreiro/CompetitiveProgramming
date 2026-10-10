#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e7 + 2;

int limite = 0;
bool isPrime[MAXN];
vector<int> primos;
bool v[MAXN];

vector<int> crivo(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i + i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0 ; i<n; i++) cin>>vec[i];
    sort(vec.begin(), vec.end());
    limite = gcd(vec[0], vec[n-1]);
    int aux;
    for(int i = 0; i < n; i++){
        if(vec[i] % limite != 0){ cout<<"NO\n"; return; }
        aux = vec[i] / limite;
        if(isPrime[aux]){
            if(v[aux]){ cout<<"NO\n"; return; }
            v[aux] = true;
            continue;
        }
        for(const auto it : primos){
            if(it > aux) break;
            else if(aux % it == 0){
                if(v[it]){ cout<<"NO\n"; return; }
                v[it] = true; 
            }
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    primos = crivo();
    solve();
}