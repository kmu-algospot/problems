#include <iostream>

using namespace std;
double cache[1002][1002];
double snail(int day, int current, int& m, int& n) {
	if (day == m) {
		return current >= n ? 1 : 0;
	}
	if (cache[day][current] != -1) {
		return cache[day][current];
	}
	return cache[day][current] = 0.25*snail(day + 1, current + 1, m, n) + 0.75*snail(day + 1, current + 2, m, n);
}
int main() {
	int C, n, m;
	scanf("%d", &C);
	while (C--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= 1001; ++i) {
			for (int j = 0; j <= 1001; ++j) {
				cache[i][j] = -1;
			}
		}
		printf("%.10lf\n", snail(0, 0, m, n));
	}
	return 0;
}
