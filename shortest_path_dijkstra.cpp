#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
 
const ll mod = 1e9+7;
const ll INF = 100000000000000000;
ll n, m, k, l, r, x, y, z, sum, cnt;
string s,t;
bool ok = false;
vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    adj.assign(n, vector<pair<ll,ll>>{});
    for(ll i = 0; i < m; i++){
        cin >> x >> y >> z;
        adj[x-1].push_back({y-1,z});
        adj[y-1].push_back({x-1,z});
    }
    vector<ll> d,p;
    dijkstra(0,d,p);
    cout << d[n-1];
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