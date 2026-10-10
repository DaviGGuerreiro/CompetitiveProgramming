#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int resposta, aux;
char aux2;
map<string, int> quantidade;
map<int, string> dicionario;
map<char, int> indicionario;
string x, y;

const int ALPHA = 10, off = '0';
struct Node {
    array<Node*, ALPHA> nxt;
    int terminal = 0; 
    Node() { nxt.fill(NULL); }
};

struct Trie {
	Node* root;
	Trie(){ root = new Node(); }
	
	void add(string &s){
		Node* t = root;
		for(auto c : s){ c -= off;
			if(!t->nxt[c])
				t->nxt[c] = new Node();
			t = t->nxt[c];
            t->terminal++;
		}
	}

	int count(string &s){
		Node* t = root;
		for(auto c : s){ c -= off;
			if(!t->nxt[c]) return 0;
			t = t->nxt[c];
		}
		return t->terminal;
	}
};

void solve(){
    int n, q; cin>>n>>q;
    int indice = 0;
    for(int i = 2; i <= 9; i++){
        for(int j = indice; j < indice + 3; j++){
            dicionario[i].push_back('a' + j);
            indicionario['a' + j] = i;
        }
        indice += 3;
        if(i == 7 || i == 9){
            dicionario[i].push_back('a' + indice);
            indicionario['a' + indice] = i;
            indice++;
        }
    }
    Trie arvore;
    for(int i = 0 ; i<n; i++){
        cin>>x;
        for(int i = 0 ; i < x.size(); i++){
            x[i] = (indicionario[x[i]] + '0');
        }
        arvore.add(x);
    }
    for(int i = 0; i<q; i++){
        cin>>x;
        cout<<arvore.count(x)<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}