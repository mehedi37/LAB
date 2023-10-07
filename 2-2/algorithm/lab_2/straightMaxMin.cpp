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

vector<int> straight_max_min(const vector<int>& a) {
    vector<int> ans;
    int max = a[0], min = a[0];
    for (auto i : a) {
        if (i > max) max = i;
        else if (i < min) min = i;      // else if is used to reduce the number of comparisons
    }
    ans.push_back(max);
    ans.push_back(min);
    return ans;
}

int main() {
    fast
    int n; cin >> n;
    return 0;
}