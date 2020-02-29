//
// Created by juheeSVT on 2020-02-29.
//

// IDE 에서 답 잘 나오는데 채점서버에서 런타임 에러
// RTE (SIGSEGV: segmentation fault, probably incorrect memory access or stack overflow)

#include <iostream>

const int MAX = 50;

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
                if ( subSequence[j] > localMax && sequence[j] < sequence [i]) {
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
