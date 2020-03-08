#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char c[10005];
int m[10005];
int l;

int lv(int s, int n){
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
        }
        else if (abs(r) == abs(atoi(q) - atoi(p))) {
            if (lv == 0) {
                if(y != r*-1 && y != 0){
                    lv = 10;
                    break;
                }
                y = r;
                lv = 4;
            } else if (lv != 4) {
                lv = 10;
                break;
            }
        }
        else{
            lv = 10;
            break;
        }
        r = atoi(q) - atoi(p);
    }
    return lv;
}

// s : 시작 위치, n : 끝 위치
int dp(int s) {
    // 문자열 길이보다 클 때

    // 값이 이미 있을 때
    if (s == l){
        return 0;
    }

    int& ret = m[s];

    if (ret != -1){
        return ret;
    }
    ret = 9999999;
    for(int L = 3; L <= 5; ++L){
        if(s + L <= l){
            ret = min(ret, dp(s+L) + lv(s, s+L));
        }
    }

//    ret = min(min(min(dp(n, n+5), dp(n, n+4)), dp(n, n+3)) + lv, ret);

    return ret;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", c);
        l = strlen(c);
        fill_n(m, l, -1);
        printf("%d ", dp(0));
//        for(int j = 0; j < l; ++j){
//            printf("%d ", m[j]);
//        }

    }

    return 0;
}
