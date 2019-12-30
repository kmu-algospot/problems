#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

const double INF = 99999;
double solve(int currentNode, vector < bool > & check, vector < vector < double >> & dist) {
  if (check[currentNode]) {
    return INF;
  }
  check[currentNode] = true;
  bool finished = true;
  for (int ci = 0; ci < dist.size(); ++ci) {
    if (!check[ci]) {
      finished = false;
    }
  }
  if (finished) {
    check[currentNode] = false;
    return 0;
  }
  double ret = INF;
  for (int j = 0; j < dist.size(); ++j) {
    if (dist[currentNode][j] != 0) {
      ret = min(solve(j, check, dist) + dist[currentNode][j], ret);
    }
  }
  check[currentNode] = false;

  return ret;
}
int main() {
  int C;
  scanf("%d", & C);
  while (C--) {
    int N;
    double temp, ret = INF;
    scanf("%d", & N);
    vector < bool > check(N, false);
    vector < vector < double >> dist(N, vector < double > (N, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%lf", & temp);
        dist[i][j] = temp;
      }
    }
    for (int i = 0; i < N; ++i) {
      ret = min(solve(i, check, dist), ret);
    }
    printf("%.10lf\n", ret);

  }
}
