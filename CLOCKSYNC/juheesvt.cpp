#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SWITCH_NUM = 10;
const int CLOCK_NUM = 16;
const int INF = 99999;


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

void tictoc(int clock[], int currentButton) {           //  시계 돌리기
    
    for (int i = 0; i < button[currentButton].size(); i++) {
        if (clock[button[currentButton][i]] == 12) {
            clock[button[currentButton][i]] = 3;
        }
        else {
            clock[button[currentButton][i]] += 3;
        }
    }
}

bool isAllTwelve(const int clock[]) {
    for (int _clock = 0; _clock < CLOCK_NUM; _clock++) {
        if (clock[_clock] != 12) {
            return false;
        }
    }
    return true;

}
int clockSyn(int clock[], int currentButton) {

    if (currentButton == SWITCH_NUM)    return isAllTwelve(clock) ? 0 : INF;
    
    int minn = INF;
    for (int _current_button_count = 0; _current_button_count < 4; _current_button_count++) {
        minn = min(_current_button_count + clockSyn(clock, currentButton + 1), minn);
        tictoc(clock, currentButton);
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
        int result = clockSyn(clock, 0);
        if  (result == INF) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", result);
        }
    }

    return 0;
}
