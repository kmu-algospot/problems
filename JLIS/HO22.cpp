#include <iostream>
#include <algorithm>
using namespace std;

int la[105], lb[105];
const long long NEGINF = numeric_limits<long long>::min();
int mm[105][105], n, m;

int jlis(int a, int b) {


    int& ret = mm[a + 1][b + 1];

    if (mm[a + 1][b + 1] != -1) {
        return mm[a + 1][b + 1];
    }

    ret = 0;


    long long ma = (a == -1 ? NEGINF : la[a]);
    long long mb = (b == -1 ? NEGINF : lb[b]);
    long long mx = max(ma, mb);

    for (int i = a + 1; i < n; ++i) {
        if (mx < la[i]) {
            ret = max(ret, jlis(i, b) + 1);
        }
    }
    for (int i = b + 1; i < m; ++i) {
        if (mx < int(lb[i])) {
            ret = max(ret, jlis(a, i) + 1);
        }
    }
    return ret;
}


int main() {

    int c;

    scanf("%d", &c);

    for (int i = 0; i < c; ++i) {
        scanf("%d %d", &n, &m);
        for (int j = 0; j < 101; ++j) {
            for (int k = 0; k < 101; ++k) {
                mm[j][k] = -1;
            }
        }
        for (int j = 0; j < n; ++j) {
            scanf("%d", &la[j]);
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &lb[j]);
        }
        int answer = jlis(-1, -1);
        printf("%d\n", answer);
    }
    return 0;
}
