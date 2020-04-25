#include <iostream>

int arr[55][55], cnt[55], n, s, gs = 0;
double m[105][55], dap;

double number(int p, int d) {
    if (d == 0) {
        if (s == p) {
            return 1;
        } else {
            return 0;
        }
    }

    double &ret = m[d][p];
    if (ret > -1) {
        ++gs;
        return ret;
    }

    ret = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[p][i]) {
            ret += (double) number(i, d - 1) / (double) cnt[i];
        }
    }
    return ret;
}

int main() {
    int c, d, t, q;
    scanf("%d", &c);
    for (int k = 0; k < c; ++k) {
        scanf("%d %d %d", &n, &d, &s);
        for (int i = 0; i < n; ++i) {
            cnt[i] = 0;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
                if (arr[i][j]) {
                    ++cnt[i];
                }
            }
        }
        for (int i = 0; i <= d; ++i) {
            for (int j = 0; j < n; ++j) {
                m[i][j] = -1;
            }
        }

        scanf("%d", &t);

        for (int i = 0; i < t; ++i) {
            scanf("%d", &q);
            printf("%.10f ", number(q, d));
        }
    }
    return 0;
}
