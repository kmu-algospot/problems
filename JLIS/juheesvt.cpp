//
// Created by juheeSVT on 2020-02-29.
//

#include <iostream>
#include <algorithm>

const long long NEGINF = std::numeric_limits<long long>::min();
int n, m , A[100] , B[100];
int cache [101] [101] ;

int jLis(int, int);

int main() {
    int testCase;
    scanf("%d", &testCase);

    while (testCase--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cache[i][j] = -1;
            }
        }
        printf("%d", jLis(-1,-1));
    }
}


int jLis(int indexA, int indexB) {

    if (cache[indexA+1][indexB+1] != -1)    return cache[indexA+1][indexB+1];

    cache[indexA+1][indexB+1] = 2;

    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = std::max(a,b);

    for ( int i = indexA + 1; i < n; i++) {
        if (maxElement < A[i]) {
            cache[indexA+1][indexB+1] = std::max(cache[indexA+1][indexB+1], jLis(i, indexB)+1);
        }
    }
    for ( int j = indexB + 1; j < n; j++) {
        if (maxElement < B[j]) {
            cache[indexA+1][indexB+1] = std::max(cache[indexA+1][indexB+1], jLis(indexA, j)+1);
        }
    }
    return cache[indexA+1][indexB+1];
}

