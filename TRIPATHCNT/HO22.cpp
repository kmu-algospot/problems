#include <iostream>

using namespace std;

int c, n;

int main() {
    int mx = 0, answer = 0;
    int t[105][105] = {0,};
    int m[105][105] = {0,};
    int cnt[105][105] = {0,};

    scanf("%d", &c);
    for(int k = 0; k < c; ++k){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                scanf("%d", &t[i][j]);
                m[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
        cnt[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0) {
                    m[i][j] = t[i][j];
                }
                else if(j==0){
                    m[i][j] = m[i-1][j] + t[i][j];
                    cnt[i][j] = cnt[i-1][j];
                }
                else if(j==i){
                    m[i][j] = m[i-1][j-1] + t[i][j];
                    cnt[i][j] = cnt[i-1][j-1];
                }
                else{
                    if(m[i - 1][j] + t[i][j] > m[i - 1][j - 1] + t[i][j]){
                        m[i][j] = m[i - 1][j] + t[i][j];
                        cnt[i][j] = cnt[i-1][j];
                    }
                    else if(m[i - 1][j] + t[i][j] < m[i - 1][j - 1] + t[i][j]){
                        m[i][j] = m[i - 1][j-1] + t[i][j];
                        cnt[i][j] = cnt[i-1][j-1];
                    }
                    else if(m[i - 1][j] + t[i][j] == m[i - 1][j - 1] + t[i][j]){
                        m[i][j] = m[i - 1][j] + t[i][j];
                        cnt[i][j] = cnt[i-1][j] + cnt[i-1][j-1];
                    }
                }
            }
        }
        mx = 0;
        for (int j = 0; j < n; ++j) {
            if (mx < m[n - 1][j]) {
                mx = m[n - 1][j];
                answer = cnt[n - 1][j];
            } else if (mx == m[n - 1][j]) {
                answer += cnt[n - 1][j];
            }
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j <= i; ++j) {
//                printf("%d ", cnt[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d ", answer);
    }
    return 0;
}
