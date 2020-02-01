//
// Created by juheeSVT on 2020-02-01.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int fanMeeting(const string& idol, const string& fan) {
    
    int cnt = 0;
    vector<int> male;

    // 남자 인덱스 기억
    for ( int i = 0; i < idol.size(); i++) {
        if (idol[i] == 'M')
            male.push_back(i);
    }

    for ( int i = 0; i < fan.size() - idol.size() + 1; i++) {
        bool isAble = true;
        if(male.size() != 0) {
            for (auto target : male) {
                if (fan[i+target] == 'M') {
                    isAble = false;
                }
            }
        }
        if (isAble) cnt++;
    }
    return cnt;
}

int main() {

    int testCase;
    scanf("%d", &testCase);

    string idol, fan;
    while(testCase--) {
        cin >> idol >> fan;
        cout << fanMeeting(idol, fan) << endl;
    }

}
