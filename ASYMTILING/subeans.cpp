#include <iostream>
#include <vector>

using namespace std;
int MOD = 1000000007;

vector<int> dp;

int getAll(int n) {
	if (n <= 1) return dp[n] = 1;
	int& ret = dp[n];
	if (ret != -1) return ret;
	ret = (getAll(n - 1) + getAll(n - 2)) % MOD;
	return ret;
}

int getSymmetry(int n) {
	int ans = dp[n / 2]%MOD;
	if (n % 2 == 0)
		ans = (ans + dp[n / 2 - 1]) % MOD;
	return ans;
}

int main() {
	int C;
	cin >> C;
	dp = vector<int>(101, -1);

	while (C--) {
		int N;
		cin >> N;

		int answer = (getAll(N)  - getSymmetry(N)) % MOD; //92예제 음수나오는 문제
		cout << answer << endl;
	}
	return 0;
}
