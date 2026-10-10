#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, m, d1, d2;
int ind = 0;
vector<vector<char>> grid;

int dx1[] = {0,0,1,-1};
int dy1[] = {1,-1,0,0};

int dx2[] = {1,1,-1,-1};
int dy2[] = {-1,1,-1,1};

void solve(){
    cin>>n>>m>>d1>>d2;
    grid = vector<vector<char>> (n+1, vector<char> (m+1));
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Airplane #"<<ind<<':'<<'\n';
    bool flg;
    int x, y;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=m; j++){
            if(grid[i][j] == '.'){
                grid[i][j] = '0';
                flg = false;
                for(int k = 0; k < 4; k++){
                    x = j + dx1[k];
                    y = i + dy1[k];
                    if(x >= 1 && y >= 1 && x <= m && y <= n){
                        if(grid[y][x] == 'V'){ grid[i][j] = (d1 + '0'); flg = true; break; }
                    }
                }
                if(!flg){
                    for(int k = 0; k < 4; k++){
                        x = j + dx2[k];
                        y = i + dy2[k];
                        if(x >= 1 && y >= 1 && x <= m && y <= n){
                            if(grid[y][x] == 'V'){ grid[i][j] = (d2 + '0'); flg = true; break; }
                        }
                    }
                }
            }
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--){ ind++; solve();}
}