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


vector<int> max_min(vector<int> &a, int l, int r) {         // NOLINT
    if (l == r) return {a[l], a[l]};
    if (r - l == 1) return {max(a[l], a[r]), min(a[l], a[r])};
    int mid = (l + r) / 2;
    vector<int> left = max_min(a, l, mid);
    vector<int> right = max_min(a, mid + 1, r);
    return {max(left[0], right[0]), min(left[1], right[1])};
}

vector<int> max_min_bruitForce(vector<int> &a) {    // NOLINT
    int mx = INT_MIN, mn = INT_MAX;
    for (auto &val : a) {
        if (val > mx) {
            mx = val;
        } else if (val < mn) {
            mn = val;
        }
    }
    return {mx, mn};
}

int main() {
    fast
    srand(time(0));
    int n = 10;
    vector<int> a(n);

    return 0;
}