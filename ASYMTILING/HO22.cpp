#include <iostream>

int main() {
    int c, n;
    int m[105] = {0,};
    int answer = 0, cnt;

    scanf("%d", &c);

    m[1] = 1;
    m[2] = 2;

    for (int i = 0; i < c; ++i) {
        scanf("%d", &n);

        if (m[n] == 0) {
            for (int j = 3; j <= n; ++j) {
                m[j] = (m[j - 2] + m[j - 1]) % 1000000007;
            }
        }

        if (n % 2) {
            answer = m[n] - m[(n - 1) / 2];
        } else {
            answer = m[n] - m[n / 2] - m[(n / 2) - 1];
        }
        if (answer < 0) {
            while (answer < 0) {
                answer += 1000000007;
            }
        }
        if(n==1 || n==2){
            printf("0\n");
        }
        else {
            printf("%d\n", answer % 1000000007);
        }
    }


    return 0;
}
