//
// Created by juheeSVT on 2020-02-29.
//

#include <iostream>
#include <algorithm>

const int MAX = 100;
int map[MAX][MAX];

int triangle(int r, int c, int sum,int triangleSize) {

    int localSum = sum;

    if (r==triangleSize)
        return localSum;

    localSum += map[r][c];
    return std::max(triangle(r+1,c,localSum,triangleSize), triangle(r+1,c+1,localSum,triangleSize));

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


        printf("%d\n", triangle(0,0,0,triangleSize));

    }
}
