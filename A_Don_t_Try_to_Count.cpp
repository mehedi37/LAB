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
        int n, m; cin >> n >> m;
        string x, s; cin >> x >> s;
        int op = 0;
        if (x.find(s) != string::npos) {
            cout << op << nn;
            continue;
        }
        do {
            if (x == s || x.find(s) != string::npos) break;
            x += x;
            op += 1;
        } while (x.length() <= n+m);
        if (x.find(s) != string::npos) {
            cout << op << nn;
        } else {
            cout << -1 << nn;
        }
    }
    return 0;
}