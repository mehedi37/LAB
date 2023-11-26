#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0));
  ofstream out("convexHull.txt");
  if (!out) {
    cout << "Cannot open output file.\n";
    return 1;
  }

  cout << "Enter number of points: ";
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x = rand() % 100;
    int y = rand() % 100;
    out << x << " " << y << endl;
  }

  return 0;
}