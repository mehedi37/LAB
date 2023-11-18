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
    ofstream knapsack;
    knapsack.open("knapsack.txt");
    int n;
    cout << "Enter number of items : ";
    cin >> n;
    cout << "Enter weight of each item : " << endl;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cout << "Enter value of each item : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    cout << "Capacity of knapsack : ";
    int capacity; cin >> capacity;

    knapsack << n << nn;

    for (int i = 0; i < n; i++) {
        knapsack << weight[i] << " ";
    }
    knapsack << nn;
    for (int i = 0; i < n; i++) {
        knapsack << value[i] << " ";
    }
    knapsack << nn;
    knapsack << capacity << nn;
    return 0;
}