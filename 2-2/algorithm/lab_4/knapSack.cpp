#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

void optimalSolution(vector<double> weight, vector<double> profit, double capacity) {
    multimap<double, int, greater<double>> ratio;
    for (int i{0}; i < weight.size(); i++) {
        ratio.insert({profit[i]/weight[i], i});
    }
    cout << "\n\n";

    vector<double> showRatio(weight.size(), 0);
    for (auto i : ratio) {
        showRatio[i.ss] = i.ff;
    }
    for (auto i : showRatio) {
        cout << i << " ";
    } cout << " | Ratio\n";

    double totProf = 0, totWeight = 0;
    vector<double> ans(weight.size(), 0);
    for (auto i : ratio) {
        if (totWeight >= capacity) break;
        if (totWeight + weight[i.ss] <= capacity) {
            totWeight += weight[i.ss];
            totProf += profit[i.ss];
            ans[i.ss] = 1;
        } else {
            double remain = abs(capacity - totWeight);
            totWeight += remain;
            totProf += (remain / weight[i.ss]) * profit[i.ss];
            ans[i.ss] = remain / weight[i.ss];
        }
        // cout << "Total weight : " << totWeight << " | Total profit : " << totProf << " | Object " << i.ss + 1 << " : " << weight[i.ss] << " - " << profit[i.ss] << " | " << i.ff << "\n";
    }
    for (auto i : ans) cout << i << " ";
    cout << " | Solution\n\n";
    cout << "Total weight : " << totWeight << "\n";
    cout << "Total profit : " << totProf << "\n";
}

int main() {
    ifstream knapsack;
    knapsack.open("knapsack.txt");

    double n; knapsack >> n;
    vector<double> weight(n), profit(n);

    for (double i = 0; i < n; i++) knapsack >> weight[i];
    for (double i = 0; i < n; i++) knapsack >> profit[i];

    double capacity; knapsack >> capacity;

    knapsack.close();

    cout << "Number of items : " << n << "\n\n";
    for (auto i : weight) {
        cout << i << " ";
    } cout << " | Weight\n";

    for (auto i : profit) {
        cout << i << " ";
    } cout << " | Profit\n";

    optimalSolution(weight, profit, capacity);

    // maxProfit(weight, profit, capacity);
    return 0;
}