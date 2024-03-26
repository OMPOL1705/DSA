#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

void check(){
    ll n, k;
    cin >> n, k;

    vector<ll> a(n);
    ll cur=0;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        cur+=a[i];
    }

    ll maxi = INT_MIN;
    ll sum=0;
    for(int i=0; i<n; i++){
        if(a[i]>0){
            sum += a[i];
            maxi = max(maxi, sum);
        }
        else{
            sum=0;
        }
    }
    ll modi = 10e9 + 7;
    if(maxi != INT_MIN){
        ll e=1;
        while(k>0){
            cur += 
        }
    }
}
    

int32_t main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll t=1;
    cin >> t;
    while(t--){
        check();
    }
 
    return 0;
}