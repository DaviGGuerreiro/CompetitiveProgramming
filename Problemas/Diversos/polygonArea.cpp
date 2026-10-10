#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld eps = 1e-12;

int cmp(ll a, ll b){ // mudar cmp tambem
    if(abs(a-b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{ //mudar tipo dependendo da questão
        ll x, y;
        Point(ll x = 0, ll y = 0) : x(x),y(y){}
        Point(const Point& p): x(p.x), y(p.y){}
    bool operator < (const Point &p) const{
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const Point &p) const{return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator != (const Point &p) const{return !(p == *this);}

        Point operator + (const Point &p) const{return Point(x + p.x, y + p.y);}
        Point operator - (const Point &p) const{return Point(x - p.x, y - p.y);}
        Point operator * (const ld k) const{return Point(x*k,y*k);}
        Point operator / (const ld k) const{return Point(x/k,y/k);}
        Point& operator=(const Point&) = default;
};

ld dot(const Point& p, const Point& q){return ((p.x * q.x) + (p.y * q.y));}
ll cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
ld norm(const Point& p){return hypot(p.x,p.y);}
ld dist(const Point& p, const Point& q){return hypot((p.x - q.x), (p.y - q.y));} 
ld dist2(const Point& p, const Point& q){return dot(p-q,p-q);}
Point normalize(const Point& p){return p/hypot(p.x,p.y);} //retorna vetor unitario;
ld angle(const Point& p, const Point& q){return atan2(cross(p,q), dot(p,q));}
ld angle(const Point& p){return atan2(p.y,p.x);}

void solve(){
    int n; cin>>n;
    Point origem; cin>>origem.x>>origem.y;
    Point A; cin>>A.x>>A.y;
    Point B;
    ll total = 0;
    for(int i = 0; i < n - 2; i++){
        cin>>B.x>>B.y;
        total += cross(A - origem, B - origem);
        A = B;
    }
    cout<<total<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}