
#include <iostream>

using namespace std;

int m[105][105];

int poly(int n, int l) {

    int answer = 0;
    if (n == 1) {
        return l;
    }
    if (n==0){
        return 1;
    }

    int& ret = m[n][l];
    if(ret != -1) return ret;
    ret = 0;

    for (int i = 1; i <= n; ++i) {
        ret += (i+l-1) * poly(n - i, i);
        ret = ret % 10000000;
    }
    return ret;
}

int main(int argc, const char *argv[]) {
    int c, n, answer;

    scanf("%d", &c);

    for ( int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            m[i][j] = -1;
        }
    }

    for (int i = 0; i < c; ++i) {
        scanf("%d", &n);
        answer = 0;
        for (int j = 1; j < n; ++j) {
            answer += poly(n-j, j);
        }
        printf("%d\n", answer%10000000+1);
    }
}
