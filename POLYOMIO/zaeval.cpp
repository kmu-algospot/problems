#include <iostream>

using namespace std;

const int MOD = 10000000;
const int MAX = 100;
int cache[MAX+1] = { 0 };
int poly(int count, int tot,bool isFirst) {
	//0 2
	if (tot == 0 && !isFirst) {
		return 1;
	}
	if (cache[count] != -1) {
		return cache[count];
	}
	
	
	int sum = 0;
	int gop = 1;
	int nowStart = (isFirst) ? tot : (tot<count)?tot:count;
	for (int i = nowStart; i >= 1; --i) {
		if (!isFirst) gop = (count - i + 1);
		sum = (sum+  (gop * poly(i, tot - i,false))%MOD)%MOD;
	}
	
	return cache[count] = sum;
}
int main() {
	int C, n;

	scanf("%d", &C);
	
	while (C--) {
		scanf("%d", &n);
		for (int i = 0; i <= MAX; ++i) {
			cache[i] = -1;
		}
		cout << poly(0, n,true) << endl;
	}
	
	return 0;
}
