//
// Created by juheeSVT on 2020-02-29.
// 메모이제이션 실패

#include <iostream>
#include <algorithm>

const int MAX = 100;
int map[MAX][MAX];
int cache[MAX][MAX];

int triangle(int r, int c, int sum,int triangleSize) {

    int localSum = sum;

    localSum += map[r][c];

    if ( r == triangleSize - 1 )
        return localSum;

    // 캐시하는 부분이 잘못됨. 똑같은 위치라도 위에서 내려온 경로에 따라 다르게 저장해야함
    if ( cache[r][c] != -1 )
        return cache[r][c];

    return cache[r][c] = std::max(triangle(r+1, c, localSum, triangleSize), triangle(r+1, c+1, localSum, triangleSize));

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
            for (int j = 0; j <= i; j++ ) {
                cache[i][j] = -1;
            }
        }

        printf("%d\n", triangle(0,0,0,triangleSize));

    }
}
