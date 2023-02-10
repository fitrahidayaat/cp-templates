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
vector<vector<ll>> v(100005, vector<ll>{});
bool visited[100005];

ll bfs(ll a, ll b){
    memset(visited, false, sizeof visited);
    queue<pair<ll,ll>> q;
    q.push({a, 0});
    visited[a] = true;
    while(!q.empty()){
        x = q.front().fi;
        y = q.front().se;
        q.pop();
        for(ll i = 0; i < v[x].size(); i++){
            if(!visited[v[x][i]]){
                visited[v[x][i]] = true;
                q.push({v[x][i], y+1});
            }
        }
    }
    return 0;
}

void solve() {
    
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