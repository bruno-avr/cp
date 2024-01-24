#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

const ull MAXN = 200010;

vector<ull> grafo[MAXN]; vector<ull> aresta[MAXN];
vector<ull> marc(MAXN, 0), pre(MAXN), low(MAXN), comp(MAXN), pilhaArestas(MAXN);
ull t, p;
vector<ull> pontoDeArticulacao(MAXN, 0);
vector<ull> marcAresta(MAXN, 0);
vector<vector<ull>> components;

void init(ull n) {
    t = 0, p = -1;
    for (ull i = 0; i < n; i++) {
        grafo[i].resize(0);
        aresta[i].resize(0);
        marc[i] = 0;
    }
    pontoDeArticulacao = vector<ull>(MAXN, 0);
    marcAresta = vector<ull>(MAXN, 0);
    components.clear();
}

void novaComponenteBiconexa (ull idAresta) {
    vector<ull> newComponent;
    ull a;
    do {
        a = pilhaArestas[p];
        p--;
        newComponent.push_back(a);
        if(p == -1) break;
    } while(a != idAresta);
    components.push_back(newComponent);
}

void dfs(ull v) {
    t++;
    pre[v] = t;
    low[v] = t;
    marc[v] = 1;

    ull qtdFilhos = 0;
    for (ull i = 0; i < grafo[v].size(); i++) {
        ull viz = grafo[v][i];
        ull idAresta = aresta[v][i];

        if (marcAresta[idAresta] == 1) continue;
        marcAresta[idAresta] = 1;
        p++;
        pilhaArestas[p] = idAresta;

        if (marc[viz] == 0) {
            qtdFilhos++;
            dfs(viz);
            low[v] = min(low[v], low[viz]);
            
            bool achouNovaComponente = false;
            if (v == 0 && qtdFilhos >= 2) achouNovaComponente = true;
            if (v != 0 && low[viz] >= pre[v]) achouNovaComponente = true;

            if (achouNovaComponente) {
                pontoDeArticulacao[v] = 1;
                novaComponenteBiconexa(idAresta);
            }
        } else {
            low[v] = min(low[v], pre[viz]);
        }
    }
}

int main() {
    ull t, n, e, a, b, caso = 1;
    cin >> t;
    while (t--) {
        cin >> n >> e;
        init(n);
        set<ull> s[n];
        ull total = 1;
 
        for (ull i = 0; i < e; i++) {
            cin >> a >> b; a--; b--;
            if (a == b) continue;
            if (s[a].find(b) != s[a].end() or s[b].find(a) != s[b].end()){
                total*=2;
            } else {
                grafo[a].push_back(b);
                grafo[b].push_back(a);
                aresta[a].push_back(i);
                aresta[b].push_back(i);
                s[a].insert(b);
                s[b].insert(a);
            }
        }

        dfs(0);
        novaComponenteBiconexa(-1);

        for (auto component : components) {
            total *= component.size();
        }
        
        cout << "Case " << caso++ << ": " << total << endl;
    }



    return 0;
}