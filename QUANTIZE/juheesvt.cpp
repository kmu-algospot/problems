#include<iostream>
#include <algorithm>


using namespace std;

const int INF = 987654321; 

int n;
int cache[100][11];
int A[101], pSum[101], pSqSum[101];

void precalC() {

	sort(A, A + n); 
	pSum[0] = A[0]; 
	pSqSum[0] = A[0] * A[0]; 

	for (int i = 1; i < n; ++i) { 
		pSum[i] = pSum[i - 1] + A[i]; 
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i]; 
	}
}

int minError(int lo, int hi) {
	
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int mean = int(0.5 + (double)sum / (hi - lo + 1));

	int ret = sqSum - 2*mean*sum + mean*mean*(hi - lo + 1);
	
	return ret;
}

int quantize(int from, int parts) {

	if (from == n)	return 0;

	if (parts == 0)	return INF;

	if (cache[from][parts] != -1)	return cache[from][parts];
	
	cache[from][parts] = INF;
	for (int partSize = 1; from + partSize <= n; partSize++) {
	
		cache[from][parts] = min( cache[from][parts],
			minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}

	return cache[from][parts];

}
int main() {
	int testCase, parts;
	cin >> testCase;
	while (testCase--) {
		cin >> n >> parts;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		precalC();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= parts; j++) {
				cache[i][j] = -1;
			}
		}
		cout << quantize(0, parts) << endl;
	}
}
