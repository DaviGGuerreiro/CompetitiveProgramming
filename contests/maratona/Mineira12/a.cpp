#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

priority_queue<pair<int, int>> impar, par;

void solve(){
    int n; cin>>n;
    vector<int> vec (n+1, 0);
    if(n == 1){cout<<1<<'\n'; return;}
    if(n == 2){cout<<"1 2\n"; return;}
    vec[1] = 1; vec[n] = 2;
    if((n - 2) % 2 == 0) par.push({n-2, n - (n-1)});
    else impar.push({n-2, n - (n-1)});
    pair<int, int> a, b;
    int mid, x, y;
    int z = 3;
    while(!impar.empty() || !par.empty()){
        pair<int, int> a = {0,0}, b = {0,0};
        if(!impar.empty()) a = impar.top();
        if(!par.empty()) b = par.top();
        if(a.first >= b.first){
            int ultimo = n - a.second;
            a.second = ultimo;
            a.second = a.second - a.first + 1;
            impar.pop();
            mid = a.second + ((a.first-1)/2);
            vec[mid] = z;
            if(a.second != mid){
                int tamanho = (mid - a.second);
                if(tamanho % 2 == 0){
                    par.push({tamanho, n - (mid-1)});
                }
                else{
                    impar.push({tamanho, n - (mid-1)});
                }
            }
            if(ultimo != mid){
                int tamanho = ultimo - mid;
                if(tamanho % 2 == 0){
                    par.push({tamanho, n - ultimo});
                }
                else{
                    impar.push({tamanho, n - ultimo});
                }
            }
        }
        else if(a.first == b.first - 1){
            int ultimo1 = n - a.second;
            a.second = ultimo1;
            int ultimo2 = n - b.second;
            b.second = ultimo2;
            a.second = a.second - a.first + 1;
            b.second = b.second - b.first + 1;
            if(a.second < b.second){
                impar.pop();
                mid = a.second + ((a.first - 1)/2);
                vec[mid] = z;
                if(a.second != mid){
                    int tamanho = (mid - a.second);
                    if(tamanho % 2 == 0){
                        par.push({tamanho, n - (mid-1)});
                    }
                    else{
                        impar.push({tamanho, n - (mid-1)});
                    }
                }
                if(ultimo1 != mid){
                    int tamanho = ultimo1 - mid;
                    if(tamanho % 2 == 0){
                        par.push({tamanho, n - ultimo1});
                    }
                    else{
                        impar.push({tamanho,n - ultimo1});
                    }
                }
            }
            else{
                par.pop();
                mid = b.second + ((b.first - 1)/2);
                vec[mid] = z;
                if(b.second != mid){
                    int tamanho = (mid - b.second);
                    if(tamanho % 2 == 0){
                        par.push({tamanho, n - (mid-1)});
                    }
                    else{
                        impar.push({tamanho, n - (mid-1)});
                    }
                }
                if(ultimo2 != mid){
                    int tamanho = ultimo2 - mid;
                    if(tamanho % 2 == 0){
                        par.push({tamanho, n - ultimo2});
                    }
                    else{
                        impar.push({tamanho, n - ultimo2});
                    }
                }
            }
        }
        else{
            int ultimo = n - b.second;
            b.second = ultimo;
            b.second = b.second - b.first + 1;
            par.pop();
            mid = b.second + ((b.first - 1)/2);
            vec[mid] = z;
            if(b.second != mid){
                int tamanho = (mid - b.second);
                if(tamanho % 2 == 0){
                    par.push({tamanho, n - (mid - 1)});
                }
                else{
                    impar.push({tamanho, n - (mid - 1)});
                }
            }
            if(ultimo != mid){
                int tamanho = ultimo - mid;
                if(tamanho % 2 == 0){
                    par.push({tamanho, n - ultimo});
                }
                else{
                    impar.push({tamanho, n - ultimo});
                }
            }
        }
        z++;
    }
    for(int i = 1; i<=n; i++){
        cout<<vec[i]<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}