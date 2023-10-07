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



vector<int> recursive_max_min(const vector<int>& a, int i, int j, int max, int min, int steps) {
    int mid = (i+j)/2;
    if (i == j) {
        steps++;
        max = min = a[0];
        return {max, min, steps};
    } else if (i == j-1) {
        if (a[i] < a[j]) {
        steps++;
            max = a[j], min = a[i];
        } else {
        steps++;
            max = a[i], min = a[j];
        }
        return {max, min, steps};
    } else {
        mid = (i+j)/2;
        vector<int> left = recursive_max_min(a, i, mid, max, min, steps);
        vector<int> right = recursive_max_min(a, mid+1, j, max, min, steps);
        steps += left[2] + right[2];
        max = left[0] > right[0] ? left[0] : right[0];
        min = left[1] < right[1] ? left[1] : right[1];
        return {max, min, steps};
    }
}

vector<int> straight_max_min(const vector<int>& a) {
    int steps = 0;
    steps++;
    vector<int> ans;
    steps++;
    int max = a[0], min = a[0];
    steps++;
    for (auto i : a) {
    steps++;
      if (i > max) {
        steps++;
        max = i;
        steps++;
      } else if (i < min) {
        steps++;
        min = i;      // else if is used to reduce the number of comparisons
        steps++;
      }
      steps++;
    }
    ans.push_back(max);
    steps++;
    ans.push_back(min);
    steps++;
    ans.push_back(steps);
    return ans;
}

void generate_input(int n) {
    ofstream out("input.txt");
    for (int i = 0; i < n; i++) {
        out << rand() << endl;  // NOLINT
    }
    out.close();
}

int main() {
    vector<int> a;
    int n;
    cout << "How many elements? ";
    cin >> n;
    generate_input(n);
    ifstream in("input.txt");
    int x;
    while (in >> x) {
      a.push_back(x);
    }
    in.close();

    // menu for recursion and straight method of minMax
    while (1) {
      int choice;
      cout << "1. Recursive\n2. Straight\n";
      cin >> choice;
      if (choice == 1) {
          int max = 0, min = INT_MAX;
          vector<int> res = recursive_max_min(a, 0, n-1, max, min, 0);
          cout << "Max: " << res[0] << " Min: " << res[1] << endl;
          cout << "Steps: " << res[2] << endl;
      } else if (choice == 2) {
          vector<int> ans = straight_max_min(a);
          cout << "Max: " << ans[0] << " Min: " << ans[1] << endl;
          cout << "Steps: " << ans[2] << endl;
      } else {
          cout << "Invalid choice\n";
          break;
      }
    }

    return 0;
}