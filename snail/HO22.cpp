#include <iostream>

using namespace std;

int n, m;
double mm[1005][1005];

double snail(int cnt, int h) {
    double &ret = mm[cnt][h];
    if (ret != -1.0) {
        return ret;
    }
    if (cnt == m) {
        return h >= n;
    }
    return ret = (0.25 * snail(cnt + 1, h + 1)) + (0.75 * snail(cnt + 1, h + 2));
}

int main() {

    int c;

    scanf("%d", &c);

    for (int i = 0; i < c; ++i) {
        scanf("%d %d", &n, &m);
        for (int j = 0; j < 1005; ++j) {
            for (int k = 0; k < 1005; ++k) {
                mm[j][k] = -1.0;
            }
        }
        printf("%.10lf\n", snail(0, 0));
    }
}
