//
// Created by juheeSVT on 2020-03-07.
//

#include <iostream>
#include <string>

using namespace std;


int pi(int begin);
int levelCheck(string &number);

string stringNum;
int cache[10000];

int main() {

    int testCase;


    scanf("%d", &testCase);

    while (testCase--) {
        cin >> stringNum;

        for (int i = 0; i < stringNum.size(); i++) {
            cache[i] = -1;
        }

        printf("%d\n", pi(0));

    }


}

int levelCheck(string number) {

    bool one = true, two = true, four = true,  five = true;
    for ( int i = 0 ; i < number.length() - 1; i++ ) {
        if (number[i+1] != number[i]) {
            one = false;                // 모두 같은 숫자 X
        }
        if (number[i+1]-number[i] != number[1]-number[0]) {
            two = false, five = false;
        }
    }

    for (int i = 0 ; i < number.length(); i++) {
        if (number[i] != number[i%2]) {
            four = false;
        }
    }
    if (one)    return 1;
    if (two && abs(number[1]-number[0]) == 1)  return 2;
    if (four) return 4;
    if (five) return 5;
    return 10;
}


int pi(int begin) {

    if (begin == stringNum.length()) return 0;

    if (cache[begin] != -1 )    return cache[begin];

    cache[begin] = 987654321;
    for (int i = 3; i <= 5; i++) {
        if (begin+i <= stringNum.size()) {
            cache[begin] = min(cache[begin], pi(begin+i) + levelCheck(stringNum.substr(begin, i)));
        }
    }
    return cache[begin];
}
