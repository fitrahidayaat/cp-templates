
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
ll d[] = {1,-1};
void bfs(ll a, ll b){
    deque<pair<pair<ll,ll>,ll>> q;
    q.push_front({{a,a}, 0});
    while (!q.empty()) {
        x = q.front().fi.fi;
        y = q.front().fi.se;
        z = q.front().se;
        if(x == n-1 && y == n-1){
            cout << z << "\n";
            return;
        } 
        q.pop_front();
        for(ll i = 0; i < 2; i++){
            if(d[i] + x >= 0 && d[i] + x < n && !visited[x+d[i]][y]){
                if(v[d[i] + x][y] == '1'){
                    q.push_back({{d[i]+x, y}, z + 1});
                    visited[d[i] + x][y] = true;
                } else{
                    q.push_front({{d[i]+x, y}, z});
                    visited[d[i] + x][y] = true;
                }
            }
            if(d[i] + y >= 0 && d[i] + y < n && !visited[x][y+d[i]]){
                if(v[x][y+d[i]] == '1'){
                    visited[x][y+ d[i]] = true;
                    q.push_back({{x, d[i]+ y}, z + 1});
                } else{
                    visited[x][y + d[i]] = true;
                    q.push_front({{x, y+d[i]}, z});
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> v[i][j];
            visited[i][j] = false;
        }
    }
    bfs(0, 0);
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