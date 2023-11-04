// WAKE UP TO REALITY - Ghost of the uchiha
#include<bits/stdc++.h>
#define ff first
#define ss second
#define nn '\n'
#define prime 1000000007
#define read(_a, _n) for (auto i = 0; i < _n; i++) cin >> _a[i];
#define show(_a) for (auto &val : _a) cout << val << " ";
#define all(_a) _a.begin(), _a.end()
#define mx(_a) *max_element(all(_a))
#define mn(_a) *min_element(all(_a))
using namespace std;
typedef long long ll;
#define fast   ios_base::sync_with_stdio(0); cin.tie(0);
// Use M_PI for pi

int main() {
    fast
    int tc;
    cin >> tc;
    while (tc--) {
        vector<ll> a(3);
        read(a, 3);
        sort(all(a));
        for (auto &val : a) {
            vector<ll> b;
            b.push_back(floor(val/2));
            b.push_back(ceil(val/2));
            ll flr = floor(b.back()/2);
            ll cel = ceil(b.back()/2);
            b.pop_back();
            ll flr2 = floor(b.back()/2);
            ll cel2 = ceil(b.back()/2);
            if (flr == cel && cel == flr2 && flr2 == cel2) {continue;}
            else {
                cout << "NO" << nn;
                break;
            }
        }
    }
    return 0;
}