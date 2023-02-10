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
char v[1005][1005];
bool visited[1005][1005];
ll d[2] = {1,-1};
ll bfs(ll a, ll b){
    memset(visited, false, sizeof visited);
    queue<pair<pair<ll,ll>,ll>> q;
    q.push({{a,b}, 0});
    visited[a][b] = true;
    while(!q.empty()){
        x = q.front().fi.fi;
        y = q.front().fi.se;
        z = q.front().se;
        q.pop();
        for(ll i = 0; i < 2; i++){
            if(x + d[i] >= 1 && x + d[i] <= n){
                if(v[x+d[i]][y] != '#' && !visited[x+d[i]][y]){
                    q.push({{x+d[i], y}, z + 1});
                    visited[x+d[i]][y] = true;
                }
            }
            if(y + d[i] >= 1 && y + d[i] <= m){
                if(v[x][y+d[i]] != '#' && !visited[x][y+d[i]]){
                    q.push({{x, y+d[i]}, z + 1});
                    visited[x][y+d[i]] = true;
                }
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