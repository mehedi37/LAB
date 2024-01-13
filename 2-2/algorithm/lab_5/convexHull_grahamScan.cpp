#include <bits/stdc++.h>
using namespace std;

class Point {
public:
  int x, y;
};
Point p0;

Point nextToTop(stack<Point> &S) {
  Point p = S.top();
  S.pop();
  Point res = S.top();
  S.push(p);
  return res;
}

int distSq(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r) {
  /*
    distance matrix
    | q.x - p.x  r.x - p.x |
    | q.y - p.y  r.y - p.y |

    if determinant is 0, then points are collinear
    if determinant is positive, then points are clockwise : 1
    if determinant is negative, then points are anti-clockwise : 2
  */

  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0)
    return 0;
  return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;
  int o = orientation(p0, *p1, *p2);
  if (o == 0)
    return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
  return (o == 2) ? -1 : 1;
  /*
    o == 2 means p2 is more anti-clockwise than p1
    so p2 should come before p1
    return -1 will swap p1 and p2
    return 1 will not swap p1 and p2
  */
}

void convexHull(vector<Point> points, int n) {
  int ymin = points[0].y, min = 0;
  for (int i = 1; i < n; i++)
  {
    int y = points[i].y;
    if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
      ymin = points[i].y, min = i;
  }
  swap(points[0], points[min]);
  p0 = points[0];   // global variable
  qsort(&points[1], n - 1, sizeof(Point), compare);
  int m = 1;
  for (int i = 1; i < n; i++)
  {
    while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
      i++;
    points[m] = points[i];
    m++;
  }
  if (m < 3)
    return;     // no convex hull (atleast 3 points needed to form a polygon | Triangle)
  stack<Point> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);
  for (int i = 3; i < m; i++) {
    while (orientation(nextToTop(S), S.top(), points[i]) != 2)
      S.pop();
    S.push(points[i]);
  }
  while (!S.empty()) {
    Point p = S.top();
    cout << "(" << p.x << ", " << p.y << ")" << endl;
    S.pop();
  }
}

int main() {
  ifstream in("convexHull.txt");
  vector<Point> points;
  Point temp;

  while (!in.eof()) {
    in >> temp.x >> temp.y;
    points.push_back(temp);
  }
  int n = points.size();
  convexHull(points, n);
  return 0;
}