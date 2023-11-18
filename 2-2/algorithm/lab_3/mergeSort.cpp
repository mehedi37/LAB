#include<bits/stdc++.h>
#define ff first
#define ss second
#define nn '\n'
#define prime 1000000007
#define read(a, n) for (auto i = 0; i < n; i++) cin >> a[i];
#define show(a) for (auto &v : a) cout << v << endl;
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(a(a))
#define mn(a) *min_element(a(a))
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0);


int mergeState = 1;
// Here v = vector, l = left index, m = middle index, r = right index
void merge(vector<int>& v, int const l, int const m, int const r) {
    int const n1 = m - l + 1;
    int const n2 = r - m;

    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (auto i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (auto j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    auto i = 0, j = 0;
    int k = l;

    // Merge the temp vectors back into v[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
    cout << "Merge state " << mergeState++ << ": ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// l is for left index and r is right index of the sub-vector of v to be sorted
void mergeSort(vector<int>& v, int const l, int const r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

int main() {
    // cout << "Enter the number of elements: ";
    // int n; cin >> n;
    vector<int> v;

    // srand(time(0));
    // for (auto &val : v)
    //     val = rand();  // NOLINT

    // ofstream fout("input.txt");
    // for (auto &val : v)
    //     fout << val << endl;

    ifstream fin("input.txt");
    while(!fin.eof()) {
        int val; fin >> val;
        v.push_back(val);
    }

    // count the time taken here
    mergeSort(v, 0, v.size() - 1);
    // cout << "Sorted array using merge sort is : ";
    // show(v);
    return 0;
}