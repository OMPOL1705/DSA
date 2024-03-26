#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

void check(){
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    vector<ll> arr;
    int one = s/k;

    if(one < b){
        cout << "-1\n";
        return;
    }
    else if(one==b){
        arr.push_back(s);
        while(arr.size() < n){
            arr.push_back(0);
        }
    }
    else{
        while((ll)(s/k) != (ll)b){
            arr.push_back(k-1);
            s -= k-1;
        }
        arr.push_back(s);
        while(arr.size()<n){
            arr.push_back(0);
        }

        if(arr.size()>n){
            cout << "-1\n";
            return;
        }
    }

    for(auto i : arr){
        cout << i << " ";
    }
    cout << "\n";
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