//
// Created by juheeSVT on 2020-02-29.
//

#include <iostream>

// 수열의 최대 크기는 500임
const int MAX = 500;

int main() {

    int testCase, subSequenceSize;
    int sequence[MAX];
    int subSequence[MAX] = {0,};

    scanf("%d", &testCase);

    while ( testCase-- ) {

        scanf("%d", &subSequenceSize);
        for ( int i = 0 ; i < subSequenceSize; i++ ) {
            scanf("%d", &sequence[i]);
        }

        subSequence[0] = 1;

        int localMax, max = 0;
        for (int i = 1; i < subSequenceSize; i++ ) {
            localMax = 0;
            for ( int j = 0; j < i; j++ ) {
                if ( sequence[j] < sequence [i] && subSequence[j] > localMax  ) {
                    localMax = subSequence[j];
                }
            }
            subSequence[i] = localMax + 1;

            if ( subSequence[i] > max ) {
                max = subSequence[i];
            }
        }
        printf("%d\n", max);
    }
}
