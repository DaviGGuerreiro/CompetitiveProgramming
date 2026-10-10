#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double eps = 1e-9;

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

vector<Point> pontos; int aux = 1;

bool OI_, TI_, OP_ ,AR_, TOP_;

void parametros(){
    Point L, R;
    vector<double> lados (4);
    vector<Point> vetores (4);
    for(int i = 1; i<=4; i++){
        L = pontos[i-1]; R = pontos[i%4];
        lados[i-1] = norm(R - L);
        vetores[i-1] = normalize(R-L);
    }
    if(abs(lados[0] - lados[2]) < eps && abs(lados[1] - lados[3]) < eps){
        OI_ = true;
        if(abs(lados[0] - lados[1]) < eps ) TI_ = true;
    }
    if(abs(dot(vetores[0], vetores[2])) == 1 || abs(dot(vetores[1], vetores[3])) == 1){
        OP_ = true;
        if(abs(dot(vetores[0], vetores[2])) == 1 && abs(dot(vetores[1], vetores[3])) == 1) TOP_ = true;
    }
    if(dot(vetores[0], vetores[1]) == 0 || dot(vetores[1], vetores[2]) == 0 || dot(vetores[2], vetores[3]) == 0 || dot(vetores[3], vetores[0]) == 0) AR_ = true;
}


void solve(){
    OI_ = false, TI_ = false, OP_ = false, AR_ = false, TOP_ = false;
    pontos = vector<Point> (4);
    for(int i = 0; i<4; i++){
        cin>>pontos[i].x>>pontos[i].y;
    }
    parametros();
    if(TI_ && AR_) cout<<"Case "<<aux<<':'<<" Square\n";
    else if(OI_ && AR_) cout<<"Case "<<aux<<':'<<" Rectangle\n";
    else if(TI_ && !AR_) cout<<"Case "<<aux<<':'<<" Rhombus\n";
    else if(OI_ && !AR_) cout<<"Case "<<aux<<':'<<" Parallelogram\n";
    else if(OP_ && !TOP_) cout<<"Case "<<aux<<':'<<" Trapezium\n";
    else cout<<"Case "<<aux<<':'<<" Ordinary Quadrilateral\n";
    aux++;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}