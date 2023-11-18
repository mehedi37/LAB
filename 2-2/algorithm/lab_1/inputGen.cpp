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
    int n;
    cout << "Enter how many numbers : "<< endl;
    cin >> n;
    ofstream out;
    out.open("search_i.txt");
    srand(time(nullptr));
    vector<int> v;
    for (int i{0}; i < n; i++) {
        v.push_back(rand());
    }
    sort(all(v));
    for (auto i : v) {
        out << i << endl;
    }
    out.close();
    return 0;
}