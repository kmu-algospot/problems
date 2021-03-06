#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int l[105], d[105], dd[105];

bool compare(int a, int b) {
    if (d[a] == d[b]) {
        return false;
    }
    return d[a] > d[b];
}

int main() {
    int c, n, s, hap = 0, r = 0;
    float avr = 0;
    long long answer = 0;

    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        scanf("%d %d", &n, &s);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &l[j]);
        }
        sort(l, l + n);

        for (int j = 1; j < n; ++j) {
            d[j] = l[j] - l[j - 1];
            dd[j] = j;
        }

        if(n < s){
            s = n;
        }

        sort(dd + 1, dd + n, compare);
        sort(dd + 1, dd + s);

        dd[0] = 0;
        dd[s] = n;

        for (int j = 0; j < s; ++j) {
            hap = 0;
            for (int k = dd[j]; k < dd[j + 1]; ++k) {
                hap += l[k];
            }

            avr = (float) hap / (dd[j + 1] - dd[j]);
            r = floor(avr + 0.5);
            for (int k = dd[j]; k < dd[j + 1]; ++k) {

                answer += (l[k] - r) * (l[k] - r);

            }
        }
        printf("%d\n", answer);
        answer = 0;
    }
}
