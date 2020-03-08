#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char c[10005];
int m[10005];
int l;


// s : 시작 위치, n : 끝 위치
int dp(int s, int n) {
    // 문자열 길이보다 클 때
    if (n > l) {
        return 9999999;
    }


    // 난이도 계산
    int lv = 0;
    char p[2];
    char q[2];
    int r;
    int y = 0;

    // 1, 2번째 숫자들의 차
    p[0] = c[s];
    q[0] = c[s + 1];
    r = atoi(q) - atoi(p);

    for (int i = s + 1; i < n - 1; ++i) {
        p[0] = c[i];
        q[0] = c[i + 1];
        if (r == atoi(q) - atoi(p)) {
            if (r == 0) {
                if (lv == 0) {
                    lv = 1;
                } else if (lv != 1) {
                    lv = 10;
                    break;
                }
            } else if (abs(r) == 1) {
                if (lv == 0) {
                    lv = 2;
                } else if (lv != 2) {
                    lv = 10;
                    break;
                }
            } else {
                if (lv == 0) {
                    lv = 5;
                } else if (lv != 5) {
                    lv = 10;
                    break;
                }
            }
        } else if (abs(r) == abs(atoi(q) - atoi(p))) {
            if (lv == 0) {
                if (y != r * -1 && y != 0) {
                    lv = 10;
                    break;
                }
                y = r;
                lv = 4;
            } else if (lv != 4) {
                lv = 10;
                break;
            }
        } else {
            lv = 10;
            break;
        }
        r = atoi(q) - atoi(p);
    }

    if ((m[n - 1] > m[s - 1] + lv) || m[n - 1] == 0) {
        m[n - 1] = m[s - 1] + lv;
    } else {
        return m[n - 1];
    }

//    printf(" %d ~ %d", s, n-1);
//    printf(" %d : %d\n", m[n-1], lv);

    if (n == l) {
//        printf("..%d..", m[n-1]);
        return m[n - 1];
    }


    return min(min(dp(n, n + 5), dp(n, n + 4)), dp(n, n + 3)) + lv;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", c);
        l = strlen(c);
        fill_n(m, l, 0);
        dp(0, 0);
        printf("%d ", m[l - 1]);
//        for(int j = 0; j < l; ++j){
//            printf("%d ", m[j]);
//        }

    }

    return 0;
}
