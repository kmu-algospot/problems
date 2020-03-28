#include <iostream>

using namespace std;
const int MOD = 1000000007;
int cache[101];
int tile(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tile(width - 2) + tile(width - 1)) % MOD;
}
int main()
{
	int C,n;
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &n);
		for (int i = 0; i <= 100; ++i) {
			cache[i] = -1;
		}
		printf("%d\n", tile(n));
	}

}
