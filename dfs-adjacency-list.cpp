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

ll dfs(ll n){
    memset(visited, false, sizeof visited);
    stack<ll> st;
    st.push(n);
    visited[n] = true;
    while(!st.empty()){
        x = st.top();
        st.pop();
        for(ll i = 0; i < v[x].size(); i++){
            if(!visited[v[x][i]]){
                visited[v[x][i]] = true;
                st.push(v[x][i]);
            }
        }
    }
    return k;
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