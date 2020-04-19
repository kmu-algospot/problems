#include <iostream>

using namespace std;

const int MOD = 10000000;
const int MAX = 100;
int cache[MAX+1][MAX+1] = { 0 };
int combi[MAX + 1][MAX + 1] = { 0 };
int poly(int count, int tot,bool isFirst) {
	if (tot == 0 && !isFirst) {
		return 1;
	}
	if (cache[tot][count] != -1) {
		return cache[tot][count];
	}
		
	int sum = 0;
	int gop = 1;

	for (int i = tot; i >= 1; --i) {
		if (!isFirst) gop = count+i-1;
		sum = (sum+  (gop * poly(i, tot - i,false))%MOD)%MOD;
		cache[tot][count] = sum;
	}
	
	return cache[tot][count];
}
int main() {
	int C, n;

	scanf("%d", &C);
	
	while (C--) {
		scanf("%d", &n);
		for (int i = 0; i <= MAX; ++i) {
			for (int j = 0; j <= MAX; ++j) {
				cache[i][j] = -1;
			}
		}
		cout << poly(0, n,true) << endl;
	}
	
	return 0;
}
