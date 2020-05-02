#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    int c;
    int n, w, mx = 0, mi = 0, g = 0;
    int b[105], z[105], m[1005][105], gs[1005], mz[1005];
    char s[1005][105], answers[1005][105];

    scanf("%d", &c);
    for (int k = 0; k < c; ++k) {
        scanf("%d %d", &n, &w);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            scanf("%d", &b[i]);
            scanf("%d", &z[i]);
            strcpy(answers[i], "");
        }
        mx = 0;
        g = 0;
        for (int j = 0; j <= w; ++j) {
            mz[j] = 0;
            gs[j] = 0;
            for (int i = 0; i < n; ++i) {
                m[j][i] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mz[b[i]] < z[i]) {
                mz[b[i]] = z[i];
                copy(m[0], m[0] + n, m[b[i]]);
                m[b[i]][i] = 1;
                gs[b[i]] = 1;
                if (mx < mz[b[i]]) {
                    mx = mz[b[i]];
                    mi = b[i];
                }
            }
        }
//        for (int j = 1; j <= w; ++j) {
//            printf("%d : %d\n", j, mz[j]);
//        }
        for (int j = 1; j <= w; ++j) {
            for (int i = 0; i < n; ++i) {
                if (mz[j - b[i]] > 0) {
                    if (m[j - b[i]][i] == 0) {
                        if (mz[j] < mz[j - b[i]] + z[i]) {
                            mz[j] = mz[j - b[i]] + z[i];
                            copy(m[j - b[i]], m[j - b[i]] + n, m[j]);
                            m[j][i] = 1;
                            gs[j] = gs[j-b[i]] + 1;
                        }
                        else if((mz[j] == mz[j - b[i]] + z[i]) && (gs[j-b[i]] + 1 < gs[j])){
                            copy(m[j - b[i]], m[j - b[i]] + n, m[j]);
                            m[j][i] = 1;
                            gs[j] = gs[j-b[i]] + 1;

                        }
                        if (mx < mz[j]) {
                            mx = mz[j];
                            mi = j;
                        }
                        else if (mx == mz[j] && gs[mi] > gs[j]) {
                            mi = j;
                        }
                    }
                }
            }
        }
//        printf("\n\n");
//        for (int j = 1; j <= w; ++j) {
//            printf("%d : %d %d\n", j, mz[j], gs[j]);
//        }
        for (int j = 0; j < n; ++j) {
            if (m[mi][j]) {
                strcpy(answers[g], s[j]);
                ++g;
            }
        }
        printf("%d %d\n", mx, g);
        for (int i = 0; i < g; ++i) {
            printf("%s\n", answers[i]);
        }
    }
    return 0;
}
