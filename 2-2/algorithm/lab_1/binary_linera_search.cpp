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

void linear_search(vector<int> a, int find) {
    int step{1}, key{0};
    for (auto i : a) {
    key++;
    step++;
        if (i == find) {
        step++;
            cout << "Number found | Key : " << key << " | Step : " << step << endl;
            return;
        }
    step++;
    }
    step++;
    cout << "Number not found | Key : " << key << " | Step : " << step << endl;
}

void binary_search(vector<int> a, int find) {
    int step{1}, key{0};
    sort(all(a));
    // show(a);
    step++;
    int l = 0, r = a.size()-1;
    // cout << l << " " << r << endl;
    step++;
    int mid = 0;
    step++;
    while (l <= r) {
        key++;
    step++;
        mid = (l+r)/2;
        // cout << " mid : " << mid << " | l : " << l << " | r: " << r << endl;
    step++;
        if (find < a[mid]) {
    step++;
            r = mid;
    step++;
        } else if (find > a[mid]) {
    step++;
            l = mid;
    step++;
        } else if (find == a[mid]) {
    step++;
            cout << "Number found | Key : " << key << " | Step : " << step << endl;
            return;
    step++;
        }
    step++;
    }
    cout << "Number not found | Key : " << key << " | Step : " << step << endl;
    step++;
}


int main() {
    // input from "search_i.txt"
    ifstream in;
    in.open("search_i.txt");
    vector<int> a;
    while (!in.eof()) {
        int number = 0;
        in >> number;
        a.push_back(number);
    }
    in.close();
    a.pop_back();

    int choice{-1};
    cout << "Enter a number to find !" << endl;
    int find{0};
    cin >> find;
    while (true) {
        cout << "1) Linear Search\n";
        cout << "2) Binary Search\n";
        cout << "2) Enter choice : ";
        cin >> choice;
        if (choice == 1) {
            linear_search(a, find);
        } else if (choice == 2) {
            binary_search(a, find);
        } else {
            cout << "Invalid Number !";
            break;
        }
    }
    return 0;
}