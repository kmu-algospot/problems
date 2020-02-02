//
// Created by juheeSVT on 2020-02-01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addTo(vector<int>& a, vector<int>& b, int k);
void subFrom(vector<int>& a, const vector<int>& b);
vector<int> multiply(const vector<int>& a, const vector<int>& b);
void normalize(vector<int>& num);

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
    vector<int> b1(b.begin() + min<int>(b.size() , half),b.end());

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

void normalize(vector<int>& num){
    num.push_back(0);

    for (int i = 0; i < num.size(); i++) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){

    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i]*b[j];
        }
    }
    normalize(c);
    return c;
}


void addTo(vector<int>& a, const vector<int>& b, int k){

    a.resize(max(a.size(), b.size() + k));

    for (int i = 0; i < b.size(); i++) {
        a[i+k] += b[i];
    }
    normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b){

    for (int i = 0; i < a.size(); i++) {
        a[i] -= b[i];
        normalize(a);
    }
}

int main(){

    vector<int> a = { 0,0,0,0,0,0,0,1}, b = { 0,0,0,0,0,0,0,1 };
    vector<int> ret = karatsuba(a,b);

    for ( int i = ret.size(); i > 0; i--){
        cout << ret[i];
    }
}
