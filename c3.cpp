#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

void check(){
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n], b[m];
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    for(ll i=0; i<m; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    ll ans=0;
    for(int i=0; i<n; i++){
        if(a[i]>=k) break;

        for(int j=0; j<m; j++){
            if(a[i]+b[j] <= k){
                ans++;
            }
            else break;
        }
    }

    cout << ans << "\n";
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