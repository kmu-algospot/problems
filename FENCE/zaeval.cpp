#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int left, int right,vector<int>&h) {
    // 기저 사례: 판자가 하나밖에 없는 경우
    if(left == right) return h[left];
    // []eft,midl, [mid + 1,right1의 두 구간으로 문제를 분할한다.
    int mid = (left + right) / 2;
    // 분할한 문제를각개격파
    int ret = max(solve(left, mid,h) , solve(mid+1, right,h)); // 부분 문제 3:두 부분에 모두 걸치는사각형 중 가장 큰 것올 찾는다.
    int lo = mid, hi = mid+1;
    int height = min(h[lo] , h[hi]);
    // [mid,mid+1]만포함하는너비2인사각형올고려한다.
    ret = max(ret, height * 2);
    // 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
    while(left < lo || hi < right) {
        // 항상 높이가 더 높은 쪽으로 확장한다
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])) {
            ++hi;
            height = min(height, h[hi]);
        }
        else {
            --lo;
            height = min(height, h[lo]);
            
        }
        //확장한 후사각형의 넓이
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}
int main(){
    int C,N;
    scanf("%d",&C);
    while(C--){
        scanf("%d",&N);
        vector<int> h;
        for(int i = 0; i<N;++i){
            int inp;
            scanf("%d",&inp);
            h.push_back(inp);
        }
        printf("%d\n",solve(0,N-1,h));
    }
    return 0;
}
