//
// Created by juheeSVT on 2020-02-29.


#include <iostream>
#include <algorithm>

const int MAX = 100;
int map[MAX][MAX];
int cache[MAX][MAX];
int cache2[MAX][MAX];

int triangle(int r, int c,int triangleSize) {


    if ( r == triangleSize - 1 )
        return map[r][c];

    if ( cache[r][c] != -1 )
        return cache[r][c];

    return cache[r][c] = std::max(triangle(r+1, c, triangleSize), triangle(r+1, c+1,triangleSize)) + map[r][c];

}
int triangleCnt(int y, int x, int triangleSize) {

    if (cache2[y][x] != -1) return cache2[y][x];

    if (y == triangleSize - 1) {
        return 1;
    }

    int pre = cache[y + 1][x];
    int next = cache[y + 1][x + 1];
    int n1 = triangleCnt(y + 1, x, triangleSize);
    int n2 = triangleCnt(y + 1, x + 1, triangleSize);

    if (pre == next) {
        cache2[y][x] = n1 + n2;
    }
    else if (pre > next) {
        cache2[y][x] = n1;
    }
    else {
        cache2[y][x] = n2;
    }
    return cache2[y][x];
}

int main(){

    int testCase, triangleSize;

    scanf("%d", &testCase);

    while(testCase--) {
        scanf("%d", &triangleSize);

        for (int i = 0; i < triangleSize; i++) {
            for (int j = 0; j <=i ; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for (int i = 0; i < triangleSize; i++ ) {
            for (int j = 0; j < triangleSize; j++ ) {
                cache[i][j] = -1;
                cache2[i][j] = -1;
            }
        }

        triangle(0,0,triangleSize);
        printf("%d\n", triangleCnt(0,0,triangleSize));
    }
}
