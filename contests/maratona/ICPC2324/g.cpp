#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Point{ //mudar tipo dependendo da questão
        int x, y;
        Point(int x = 0, int y = 0) : x(x),y(y){}
        Point(const Point& p): x(p.x), y(p.y){}
    bool operator < (const Point &p) const{
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const Point &p) const{return x == p.x && y == p.y;}
    bool operator != (const Point &p) const{return !(p == *this);}

        Point operator + (const Point &p) const{return Point(x + p.x, y + p.y);}
        Point operator - (const Point &p) const{return Point(x - p.x, y - p.y);}
        Point operator * (const double k) const{return Point(x*k,y*k);}
        Point operator / (const double k) const{return Point(x/k,y/k);}
        Point& operator=(const Point&) = default;
};

long double cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;

map<pair<int,int>, int> indice;

vector<Point> convexHull(vector<Point>& pts, bool sorted = false){
    int n = pts.size();
    if(!sorted){
        sort(pts.begin(),pts.end());
    }
    vector<Point> lower(n+1), upper(n+1);
    int s = 0;
    for(int i = 0;i < n;i++){
        lower[s++] = pts[i];
        while(s>=3){
            Point a = lower[s-3]; Point b = lower[s-2]; Point c = lower[s-1];
            Point v1 = b-a, v2 = c - b;
            if(cross(v1,v2) >= 0){
                break;
            }
            lower[s-2] = lower[s-1];
            s--;
        }
    }
    lower.resize(s);
    s = 0;
    for(int i = 0;i < n;i++){
        upper[s++] = pts[i];
        while(s>=3){
            Point a = upper[s-3]; Point b = upper[s-2]; Point c = upper[s-1];
            Point v1 = b-a, v2 = c - b;
            if(cross(v1,v2) <= 0){
                break;
            }
            upper[s-2] = upper[s-1];
            s--;
        }
    }
    upper.resize(s-1);
    reverse(upper.begin(),upper.end());
    upper.pop_back();
    lower.insert(lower.end(),upper.begin(),upper.end());
    return lower;
}

void solve(){
    int n; cin>>n;
    vector<Point> pts (n);
    int a, b;
    for(int i = 0 ; i<n; i++){
        cin>>a>>b;
        pts[i].x = a;
        pts[i].y = b;
        indice[{pts[i].y, pts[i].x}] = i+1;
    }
    vector<Point> resposta = convexHull(pts);
    set<int> r;
    for(Point it : resposta){
        r.insert(indice[{it.y, it.x}]);
    }
    for(auto it : r){
        cout<<it<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}