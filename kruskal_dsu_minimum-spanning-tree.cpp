#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;

const ll mod = 1e9+7;
const ll INF = 1e18;
ll rnk[100005];
ll par[100005];
void make_set(ll v){
    par[v] = v;
    rnk[v] = 1;
}

ll find_set(ll u){
    if(par[u] == u){
        return u;
    }
    return par[u] = find_set(par[u]);
}

void union_set(ll u, ll v){
    ll a = find_set(u);
    ll b = find_set(v);
    if(a != b){
        if(rnk[a] < rnk[b]){
            swap(a,b);
        }
        par[b] = a;
        if(rnk[a] == rnk[b]){
            rnk[a]++;
        }
    }
}
struct edge{
    ll u, v, w;
};
void solve() {
    ll n, m; cin >> n >> m;
    vector<edge> edges(m);
    for(ll i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        make_set(edges[i].u);
        make_set(edges[i].v);
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b){
        return a.w < b.w;
    });
    ll cnt = 0;
    for(ll i = 0; i < m; i++){
        if(find_set(edges[i].u) != find_set(edges[i].v)){
            cnt += edges[i].w;
            union_set(edges[i].u, edges[i].v);
        }
    }
    cout << cnt << "\n";
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}