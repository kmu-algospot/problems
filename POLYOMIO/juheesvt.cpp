//
// Created by juheeSVT on 2020-04-18.
//

#include <iostream>

using namespace std;

const int MOD = 10000000;
int cache[101][101];

int polyonomio(int square, int first) {

    if ( square == first ) return 1;
    if ( cache[square][first] != -1 ) return cache[square][first];

    cache[square][first] = 0;

    for (int i = 1; i <= square-first; i++) {
        int temp = i + first - 1;
        cache[square][first] += (temp *= polyonomio(square - first, i));
        cache[square][first] %= MOD;
    }
    return cache[square][first];
}

int main() {
    int testCase, squareNum;
    cin >> testCase;

    while(testCase--) {
        cin >> squareNum;
        for ( int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                cache[i][j] = -1;
            }
        }
        int answer = 0;
        for (int i = 1; i <= squareNum; i++) {
            answer += polyonomio(squareNum, i);
            answer %= MOD;
        }
        cout << answer << endl;
    }
}


