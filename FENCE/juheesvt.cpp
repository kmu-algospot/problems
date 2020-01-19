//
// Created by juheeSVT on 2020-01-18.
//

#include <iostream>
#include <algorithm>
using namespace std;

int fence[20000];


int fenceFunc(int left, int right) {

    // fence가 하나라면 !!
    if (left == right)      return fence[left];

    int middle = (left + right) / 2;

    // 처음과 중간, 중간+1과 마지막 이렇게 반을 나눠서 더 큰 값 찾기
    int result = max(fenceFunc(left,middle), fenceFunc(middle+1, right));
    int lo = middle, hi = middle+1;
    int height = min(fence[lo], fence[hi]);

    result = max(result, height*2);

    while (left < lo || hi < right) {
        hi++;
        if (hi < right && (lo == left || fence[lo-1] < fence[hi+1])) {
            height = min(height, fence[hi]);
        } else {
            lo--;
            height = min(height, fence[lo]);
        }
        result = max(result, height * (hi-lo+1));
    }
    return result;
}

int main() {
    int testCase, fenceNum;
    scanf("%d", &testCase);

    for (int _test_case = 0; _test_case < testCase; _test_case++ ) {
        scanf("%d", &fenceNum);
        for ( int _fence_num = 0; _fence_num < fenceNum; _fence_num++ ) {
            scanf("%d", &fence[_fence_num]);
        }
        printf("%d\n", fenceFunc(0, fenceNum-1));
    }
}
