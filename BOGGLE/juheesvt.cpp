//
// Created by juheeSVT on 2019-12-01.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_SIZE  5

int y[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int x[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char board[MAX_SIZE][MAX_SIZE];
string currentWord;

bool boggle(int row, int col, int cnt) {
    for (int direction = 0; direction < 8; direction++) {
        if ( 0 <= row + y[direction] && row + y[direction] < MAX_SIZE &&
            0 <= col + x[direction] && col + x[direction] < MAX_SIZE) {
            if ( board[row + y[direction]][col + x[direction]] ==  currentWord[cnt] ) {
                if (cnt == currentWord.size()-1) {
                    return true;
                }
                bool check = boggle(row + y[direction], col + x[direction], cnt + 1);
                // check 가 false 일 때는 나머지 돌아야댐 !!
                if(check)
                    return check;
            }
        }
    }
    return false;
}

int main() {

    int testCase, numOfString;
    bool isExist = false;

    scanf("%d", &testCase);


    for (int i = 0; i < testCase; i++) {
        for (int r = 0; r < MAX_SIZE; r++) {
            scanf("%s\n", &board[r]);
        }
        scanf("%d", &numOfString);
        for (int k = 0; k < numOfString; k++) {
            cin >> currentWord;
            for (int r = 0; r < MAX_SIZE; r++) {
                for (int c = 0; c < MAX_SIZE; c++) {
                    if (currentWord[0] == board[r][c]) {
                        if ( boggle(r, c, 1) ) {
                            isExist = true;
                        }
                    }
                }
            }
            // c_str() : string - > char *
            if (isExist)
                printf("%s %s\n", currentWord.c_str(), "YES");
            else
                printf("%s %s\n", currentWord.c_str(), "NO");
            isExist = false;
        }
    }
}
