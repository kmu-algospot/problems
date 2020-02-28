//
// Created by juheeSVT on 2020-02-29.
// 메모이제이션 실패

#include <iostream>
#include <algorithm>

const int MAX = 100;
int map[MAX][MAX];
int cache[MAX][MAX];

int triangle(int r, int c,int triangleSize) {

    // 내려가면서 sum을 비교하는 것이 아니기때문에 localSum이 필요없음 !!
    if ( r == triangleSize - 1 )
        return map[r][c];

    if ( cache[r][c] != -1 )
        return cache[r][c];

    return cache[r][c] = std::max(triangle(r+1, c, triangleSize), triangle(r+1, c+1,triangleSize)) + map[r][c];

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

        printf("%d\n", triangle(0,0,triangleSize));

    }
}
