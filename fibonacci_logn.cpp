#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
 
const ll mod = 1e9+7;
const ll INF = 2e9;
ll n, m, k, l, r, p, q, x, y, z, sum, cnt;
string s,t;
bool ok = true;
void multiply(ll mat[2][2],ll m[2][2]){
   ll temp[2][2];
   temp[0][0]= ((mat[0][0]%mod)*(m[0][0]%mod))%mod+((mat[0][1]%mod)*(m[1][0]%mod))%mod;
   temp[0][1]= ((mat[0][0]%mod)*(m[0][1]%mod))%mod+((mat[0][1]%mod)*(m[1][1]%mod))%mod;
   temp[1][0]= ((mat[1][0]%mod)*(m[0][0]%mod))%mod+((mat[1][1]%mod)*(m[1][0]%mod))%mod;
   temp[1][1]= ((mat[1][0]%mod)*(m[0][1]%mod))%mod+((mat[1][1]%mod)*(m[1][1]%mod))%mod;
   mat[0][0] = temp[0][0]%mod;
   mat[0][1] = temp[0][1]%mod;
   mat[1][0] = temp[1][0]%mod;
   mat[1][1] = temp[1][1]%mod;
}

void mat_power(ll mat[2][2],ll n){
   if(n==1) return;
  
    mat_power(mat,n/2);
    multiply(mat,mat);
  
    ll m[2][2]={
       {1,1},
       {1,0}
       };   
    if(n%2!=0)
	    multiply(mat,m);
}

void solve() {
    cin>>n;
    n++;
    ll mat[2][2]={
        {1,1},
        {1,0}
    };   
    if(n==0) cout<< 0<<endl;
    mat_power(mat,n);
    cout<<((mat[0][1]%mod)*(mat[0][1]%mod))%mod<<endl;

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