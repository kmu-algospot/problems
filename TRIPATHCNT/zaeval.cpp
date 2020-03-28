#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int C, count = 0;
    cin >> C;
    while (C--) {
        int N;
        cin >> N;
        vector<vector<int>> mapp(N, vector<int>(N, 0));
        int maxValue = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> mapp[i][j];
                if (i - 1 >= 0) {
                    if (j - 1 >= 0) {
                        mapp[i][j] = max(mapp[i - 1][j - 1], mapp[i - 1][j]) + mapp[i][j];
                    }
                    else {
                        mapp[i][j] = mapp[i - 1][j] + mapp[i][j];
                    }
                }
                if (maxValue < mapp[i][j]) {
                    maxValue = mapp[i][j];
                    count = 1;
                }
                else if (maxValue == mapp[i][j]) {
                    count +=1;
                }
            }
        }
        cout << maxValue << endl;

    }
    return 0;
}
