#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

string naipes = "CEOP";
string s = "4567QJKA23";

map<string , int> mapa;

struct objetox{
    string p;
    bool flg;
};

bool compararx(const string& a, const string& b){
    return mapa[a] >= mapa[b];
}

bool comparar(const string& a, const string& b){
    return mapa[a] > mapa[b];
}

struct comparefuncx{
    bool operator()(const objetox& a, const objetox& b) const{
        return comparar(b.p, a.p);
    }
};

struct comparefunc{
    bool operator()(const objetox& a, const objetox& b) const{
        return comparar(a.p, b.p);
    }
};

multiset<objetox, comparefunc> A, B, C, D;

void solve(){
    string x;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            cin>>x;
            objetox y; y.p = x; y.flg = ((i+1) % 2 == 0);
            if(i == 0) A.insert(y);
            else if(i == 1) B.insert(y);
            else if(i == 2) C.insert(y);
            else if(i == 3) D.insert(y);
        }
    }
    for(int i = 0; i<3; i++){
        priority_queue<objetox, vector<objetox>, comparefuncx> pq;
        auto et = A.begin();
        pq.push(*et); A.erase(et);
        bool empate = false;
        for(int j = 0; j<3; j++){
            if(j == 0){
                if(compararx(pq.top().p, (*(B.begin())).p)){
                    auto it = B.end(); --it;
                    if(mapa[pq.top().p] == mapa[(*(it)).p]) empate = true;
                    B.erase(it);
                }
                else{
                    auto at = B.begin();
                    empate = false;
                    pq.push(*at);
                    B.erase(at);
                }
            }
            else if(j == 1){
                if(pq.top().flg == (*C.begin()).flg && !empate){
                    auto it = C.end(); --it;
                    pq.push(*it);
                    C.erase(it);
                }
                else{
                    if(compararx(pq.top().p, (*(C.begin())).p)){
                        auto it = C.end(); it--;
                        if(mapa[pq.top().p] == mapa[(*(it)).p]) empate = true;
                        C.erase(it);
                    }
                    else{
                        auto at = C.begin();
                        empate = false;
                        pq.push(*at);
                        C.erase(at);
                    }
                }
            }
            else{
                if(pq.top().flg == (*D.begin()).flg && !empate){
                    auto it = D.end(); it--;
                    pq.push(*it);
                    D.erase(it);
                }
                else{
                    if(compararx(pq.top().p, (*(D.begin())).p)){
                        auto it = D.end(); it--;
                        if(mapa[pq.top().p] == mapa[(*(it)).p]){ empate = true; }
                        D.erase(it);
                    }
                    else{
                        auto at = D.begin();
                        empate = false;
                        pq.push(*at);
                        D.erase(at);
                    }
                }
            }
        }
        if(empate) cout<<0<<' ';
        else if(pq.top().flg) cout<<2<<' ';
        else cout<<1<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string aux;
    for(int i = 0; i<s.size(); i++){
        for(const auto it : naipes){
            aux = s[i];
            aux += it;
            mapa[aux] = i;
            if(aux == "7O") mapa[aux] = 10;
            else if(aux == "AE") mapa[aux] = 11;
            else if(aux == "7C") mapa[aux] = 12;
            else if(aux == "4P") mapa[aux] = 13;
        };
    }
    solve();
    return 0;
}