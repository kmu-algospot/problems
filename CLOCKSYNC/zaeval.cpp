#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int SWITCH_NUM = 10;
const int CLOCK_NUM = 16;
const int INF = 99999;
const int SWITCH[SWITCH_NUM][6] = {
    {0,1,2,-1},
    {3,7,9,11,-1},
    {4,10,14,15,-1},
    {0,4,5,6,7,-1},
    {6,7,8,10,12,-1},
    {0,2,14,15,-1},
    {3,14,15,-1},
    {4,5,7,14,15,-1},
    {1,2,3,4,5,-1},
    {3,4,5,9,13,-1},
};

int solve(int switchNum, vector<int>& clocks) {
    if (switchNum == SWITCH_NUM)
    {
        for (int clock = 0; clock < CLOCK_NUM; ++clock) {
            if (clocks[clock] % 12) {
                return INF;
            }
        }
        return 0;
    }
    int answer = INF;
    for (int count = 0; count < 4; ++count) {
        answer = min(count + solve(switchNum + 1, clocks),answer);
        int clock = 0;

        while (SWITCH[switchNum][clock] != -1) {
            clocks[SWITCH[switchNum][clock]] += 3;
            clock++;
        }
    }
    return answer;

}
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        vector<int> clocks(CLOCK_NUM, 0);
        for (int clock = 0; clock < CLOCK_NUM; ++clock) {
            scanf("%d", &clocks[clock]);
        }
        int answer = solve(0, clocks);
        printf("%d\n",(answer == INF)?(-1):(answer));

    }
    return 0;
}
