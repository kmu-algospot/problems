#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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


vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int as = a.size();
    int bs = b.size();
    vector<int> c(as + bs-1, 0);
    for(int i = 0; i < as; ++i)
        for(int j = 0; j < bs; ++j)
            c[i+j] += a[i] * b[j];
    return c;
}

//vector a와 b는 거꾸로 뒤집혀서 들어온다.
vector<int> karatsuba(const vector<int>& a, const vector<int> & b){
    int an = a.size();
    int bn = b.size();
    
    if(an < bn) return karatsuba(b,a);
    if(an == 0 || bn == 0)return vector<int>();
    if(an<50) return multiply(a,b);
    int half = an/(int)2;
    
    //더 큰수의 절반의 뒷부분
    vector<int> a0(a.begin(),a.begin()+half);
    //더 큰수의 절반의 앞부분
    vector<int> a1(a.begin()+half,a.end());
    //더 작은수의 더 큰수 기준 절반의 뒷부분
    vector<int> b0(b.begin(),b.begin() + min(bn,half));
    //더 작은 수의 더 큰수 기준 절반의 앞부분
    vector<int> b1(b.begin() + min(bn,half),b.end());
    
    //z0 = a0 * b0
    vector<int> z0 = karatsuba(a0,b0);
    //z2 = a1 * b1
    vector<int> z2 = karatsuba(a1,b1);
    //z1 = (a0+a1) * (b0+b1) - z0 - z1
    addTo(a0,a1,0);addTo(b0,b1,0);
    vector<int> z1 = karatsuba(a0,b0);
    subFrom(z1,z0);
    subFrom(z1,z2);
    
    //z0 + z1* 10^half + z2 * 10^(half^2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half*2);
    
    return ret;
}
vector<int> toVector(string str,bool isReverse){
    vector<int> ret;
    int ss = str.size();
    ret.reserve(ss);
    for(int i = 0; i<ss;++i){
        if(isReverse)
            ret.push_back(str[i] == 'M');
        else
            ret.insert(ret.begin(),str[i]=='M');
    }
    return ret;
}
int fanMeeting(const string& idol, const string& fan) {

    int cnt = 0;
    vector<int> idolInt(idol.size()), fanInt(fan.size());

    for (int i = 0; i < idol.size(); i++) {
        idolInt[i] = (idol[i] == 'M');
    }

    // 팬은 뒤에서 부터 입력받아야댐
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
