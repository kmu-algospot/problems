#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int n, d, p;
int connected[51][51], deg[51];
double cache[51][101];
double search(int here, int days){
	if (days == 0) 
		return (here == p ? 1.0 : 0.0);
	double &ret = cache[here][days];
	if (ret > -0.5)
		return ret;

	ret = 0.0;
	for (int there =0; there <n; ++there)
	{
		if (connected[here][there]) {
			ret += search(there, days-1) / deg[there];
		}
	}
	return ret;
}
int main(){
	int C;
	cin >> C;
	while (C--){
		memset(cache, -1, sizeof(cache));
		memset(connected, 0, sizeof(connected));
		memset(deg, 0, sizeof(deg));
		cin >> n >> d >> p;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> connected[i][j];
				if (connected[i][j])
					deg[i]++;
			}

		int c;
		cin >> c;
		double ret = 0;
		while (c--){
			double sum;
			int num;
			cin >> num;
			sum = search(num,d);
			cout << fixed << setprecision(8) << sum << "\n";
		}
	}
	return 0;
}
