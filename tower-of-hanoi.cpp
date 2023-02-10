#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll towerofhanoi(ll n, ll from, ll to, ll aux){
    if(n == 1){
        cout << from << " " << to << "\n";
        return 0;
    }
    towerofhanoi(n-1,from,aux,to);
    cout << from << " " << to << "\n";
    towerofhanoi(n-1,aux,to,from);
    return 0;
}