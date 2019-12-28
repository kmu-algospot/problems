#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int CLOCK_NUM = 16;


vector< vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});


int clockSyn(int clock[], int currentButton, int currentButtonCount, int totalCount) {


    // TODO : 시계 돌린거 다시 초기화 해줘야댐
    
    if (currentButton == 10)    return -1;
    //  시계 돌리기
    for (int i = 0; i < button[currentButton].size(); i++) {
        for (int _current_button_count = 0; _current_button_count < currentButtonCount; _current_button_count++) {
            if (clock[button[currentButton][i]] == 12) {
                clock[button[currentButton][i]] = 3;
            }
            else {
                clock[button[currentButton][i]] += 3;
            }
        }
    } 

    // 기저조건
    bool isAll = true;
    for (int _clock = 0; _clock < CLOCK_NUM; _clock++) {
        if (clock[_clock] != 12) {
            isAll = false;
            break;
        }
    }

    if (isAll) {
        return totalCount;  // 버튼 9까지 안내려가고 리턴해도되나 ?
    } else {
        if (currentButton == 9 && currentButtonCount == 3) {
            return -1;
        }
    }
    int minn = 99999;
    for (int _current_button_count = 0; _current_button_count < 4; _current_button_count++) {
        minn = min(clockSyn(clock, currentButton + 1, _current_button_count, totalCount + _current_button_count), minn);

    }

    return minn;


}

int main() {
    
    int clock[16], testCase;
    
    scanf("%d", &testCase);
    for (int _test_case = 0; _test_case < testCase; _test_case++) {
        for (int _clock = 0; _clock < CLOCK_NUM; _clock++) {
            scanf("%d", &clock[_clock]);
        }
        printf("%d\n", clockSyn(clock, 0, 0, 0));
    }

    return 0;
}
