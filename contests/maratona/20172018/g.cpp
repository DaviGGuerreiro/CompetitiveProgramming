#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld eps = 1e-9;
ld pi;

int cmp(ld a, ld b){ // mudar cmp tambem
    if(abs(a-b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{ //mudar tipo dependendo da questão
        ld x, y;
        Point(ld x = 0.0, ld y = 0.0) : x(x),y(y){}
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

double dot(const Point& p, const Point& q){return ((p.x * q.x) + (p.y * q.y));}
long double cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
double norm(const Point& p){return hypot(p.x,p.y);}
double dist(const Point& p, const Point& q){return hypot((p.x - q.x), (p.y - q.y));} 
double dist2(const Point& p, const Point& q){return dot(p-q,p-q);}
Point normalize(const Point& p){return p/hypot(p.x,p.y);} //retorna vetor unitario;
double angle(const Point& p, const Point& q){return atan2(cross(p,q), dot(p,q));}
double angle(const Point& p){return atan2(p.y,p.x);}

ld resposta = 0.0;
vector<Point> vec;
vector<Point> construido (10);
vector<vector<Point>> diretor (10, vector<Point>(10));
int num = 3;

void construir(int lados, ld tamanho){
    for(int i = 0 ; i < lados; i++){
        construido[i] = diretor[lados][i+1] * tamanho;
    }
}

// iner é uma figura que não tem nenhum dos pontos. !tipo
// outer é uma figura que tem todos os pontos. tipo

bool verif(int n, bool tipo){
    for(const Point pt : vec){
        Point v0 = pt - construido[0], v1 = construido[1] - construido[0], v2 = construido[n-1] - construido[0];
        if(cross(v0,v1) > -eps || cross(v0,v2) < eps){
            if(tipo) return false;
            continue;
        }
        int l = 1, r = n-1;
        while(l != r){
            int mid = (l + r + 1)/2;
            Point v1 = construido[mid] - construido[0];
            if(cross(v0,v1) < eps){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        v0 = construido[(l+1)%n] - construido[l];
        v1 = pt - construido[l];
        if(cross(v0,v1) < eps && tipo) return false;
        else if(cross(v0,v1) > -eps && !tipo) return false;
    }
    return true;
}

ld calculo_dentro(int lados){
    ld l = 0.0, r = 4e6, mid;
    for(int i = 0; i < 200; i++){
        mid = l + ((r-l)/2.0);
        construir(lados, mid);
        if(!verif(lados, false)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return l;
}

ld calculo_fora(int lados){
    ld l = 0.0, r = 4e6, mid;
    for(int i = 0; i < 200; i++){
        mid = l + ((r-l)/2.0);
        construir(lados, mid);
        if(!verif(lados, true)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

ld calculo(int lados){
    ld r1 = calculo_dentro(lados);
    ld r2 = calculo_fora(lados);
    return r1 / r2;
}

void solve(){
    int n; cin>>n;
    vec = vector<Point> (n);
    for(int i = 0 ; i<n; i++){
        cin>>vec[i].x>>vec[i].y;
    }
    ld score = 0.0;
    for(int i = 3; i<=8; i++){
        score = calculo(i);
        if(resposta < score){
            resposta = score;
            num = i;
        }
    }
    cout<<num<<' ';
    resposta *= resposta;
    cout<<fixed<<setprecision(10)<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    pi = acos(-1.0);
    ld total = pi * 2ll, angulo, aux;
    ld se, co;
    for(int i = 3; i<=8; i++){
        aux = (total/((ld)i));
        angulo = 0.0;
        for(int j = 1; j<=i; j++){
            diretor[i][j].x = cos(angulo);
            diretor[i][j].y = sin(angulo);
            angulo += aux;
        }
    }
    solve();
}