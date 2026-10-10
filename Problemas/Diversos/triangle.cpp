#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve(){
    int x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    vector<int> lados (3);
    lados[0] = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    lados[1] = ((x2 - x3) * (x2 - x3)) + ((y2 - y3) * (y2 - y3));
    lados[2] = ((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1));
    int maior = max(lados[0], max(lados[1], lados[2]));
    if(2 * maior == lados[0] + lados[1] + lados[2]){
        cout<<"RIGHT\n";
        return;
    }
    else{
        int l1, l2, l3;
        int x4, x5, x6, y4, y5, y6;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j<4; j++){
                x4 = x1; x5 = x2; x6 = x3;
                y4 = y1; y5 = y2; y6 = y3;
                int x = dx[j];
                int y = dy[j];
                if(i == 0){
                    x4 += x; y4 += y;
                }
                else if(i == 1){
                    x5 += x; y5 += y;
                }
                else{
                    x6 += x; y6 += y;
                }
                if((x4 == x5 && y4 == y5) || (x4 == x6 && y4 == y6) || (x5 == x6 && y5 == y6)) continue;
                l1 = ((x4 - x5) * (x4 - x5)) + ((y4 - y5) * (y4 - y5));
                l2 = ((x5 - x6) * (x5 - x6)) + ((y5 - y6) * (y5 - y6));
                l3 = ((x6 - x4) * (x6 - x4)) + ((y6 - y4) * (y6 - y4));
                int maior = max(l1, max(l2, l3));
                if(2 * maior == l1 + l2 + l3){
                    cout<<"ALMOST\n";
                    return;
                }
            }
        }
    }
    cout<<"NEITHER\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}