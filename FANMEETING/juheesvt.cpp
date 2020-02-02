//
// Created by juheeSVT on 2020-02-02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k){

    a.resize(max(a.size(), b.size() + k));

    for (int i = 0; i < b.size(); i++) {
        a[i+k] += b[i];
    }
}
void subFrom(vector<int>& a, const vector<int>& b) {

    a.resize(max(a.size(), b.size()) + 1);

    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){

    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i]*b[j];
        }
    }
    //normalize(c);
    return c;
}

vector<int> karatsuba( const vector<int>& a, const vector<int>& b) {

    int an = a.size(), bn = b.size();

    // a < b, 순서 바꾸기
    if (an < bn)   return karatsuba(b,a);

    // 기저 사례 1) a나 b가 비어있는 경우
    if (an == 0 || bn == 0) return vector<int>();

    // 기저 사례 2) a가 비교적 짧을 경우 O(n^2) 알고리즘으로 변경
    if (an <= 50)    return multiply(a,b);

    int half = an / 2;

    // a와 b를  밑애서 half자리와 나머지로 분리
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size() , half), b.end());

    vector<int> z2 = karatsuba(a1,b1);
    vector<int> z0 = karatsuba(a0,b0);

    addTo(a0,a1,0);
    addTo(b0,b1,0);

    vector<int> z1 = karatsuba(a0,b0);

    subFrom(z1,z0);
    subFrom(z1,z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half*2);

    return ret;
}



int fanMeeting(const string& idol, const string& fan) {

    int cnt = 0;
    vector<int> idolInt(idol.size()), fanInt(fan.size());

    for (int i = 0; i < idol.size(); i++) {
        idolInt[i] = (idol[i] == 'M');
    }

    for (int i = 0; i < fan.size(); i++) {
        fanInt[fan.size()-i-1] = (fan[i] == 'M');
    }

    vector<int> hug = karatsuba(idolInt, fanInt);

    for ( int i = idol.size() - 1; i < fan.size(); i++) {
        if (hug[i] == 0)       cnt++;
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
