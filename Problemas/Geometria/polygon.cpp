#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double eps = 1e-9;
int t = 1;

int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{
        double x, y;
        Point(double x = 0, double y = 0) : x(x),y(y){}
        Point(const Point& p): x(p.x), y(p.y){}
    bool operator < (const Point &p) const{
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const Point &p) const{return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator != (const Point &p) const{return !(p == *this);}

        Point operator + (const Point &p) const{return Point(x + p.x, y + p.y);}
        Point operator - (const Point &p) const{return Point(x - p.x, y - p.y);}
        Point operator * (const double k) const{return Point(x*k,y*k);}
        Point operator / (const double k) const{return Point(x/k,y/k);}
        Point& operator=(const Point&) = default;
};

double dot(const Point& p, const Point& q){return ((p.x * q.x) + (p.y * q.y));}
long long cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
double norm(const Point& p){return hypot(p.x,p.y);}
double dist(const Point& p, const Point& q){return hypot((p.x - q.x), (p.y - q.y));} 
double dist2(const Point& p, const Point& q){return dot(p-q,p-q);}
Point normalize(const Point& p){return p/hypot(p.x,p.y);} //retorna vetor unitario;
double angle(const Point& p, const Point& q){return atan2(cross(p,q), dot(p,q));}
double angle(const Point& p){return atan2(p.y,p.x);}

bool dentro(Point ref, vector<Point>& pontos){
    int quantidade = 0;
    for(int i = 0; i < t; i++){
        Point L, R;
        L = pontos[i]; R = pontos[((i+1)%t)];
        if(L.x == R.x){
            if(ref.x <= L.x && ref.y >= min(L.y, R.y) && ref.y <= max(L.y, R.y)){
                if(ref.x == L.x) return true;
                quantidade++;
            }
        }
        else{
            if(ref.y == L.y && ref.x >= min(L.x, R.x) && ref.x <= max(L.x, R.x)){
                return true;
            }
        }
    }
    if(quantidade % 2 == 1) return true;
    else return false;
}

void solve(){
    while(t != 0){
        cin>>t;
        if(t == 0) continue;
        vector<Point> pontos (t);
        for(int i = 0; i < t; i++){
            cin>>pontos[i].x>>pontos[i].y;
        }
        Point ref; cin>>ref.x>>ref.y;
        bool resposta = dentro(ref, pontos);
        if(resposta) cout<<'T'<<'\n';
        else cout<<'F'<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}