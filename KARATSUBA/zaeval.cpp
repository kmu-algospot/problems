#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//자리 올림 수
void normalize(vector<int>& num) {
    num.push_back(0);
    // 자릿수 올림을 처리한다
    for(int i = 0; i < num.size(); ++i) {
        if(num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow *10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
            
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
    
}
// a+=b*(1O^k) 를 구현한다
void addTo(vector<int>& a, vector<int>& b, int k){
    for(int i = 0; i < k; ++i){
        b.insert(b.begin(),0);
    }
    for(int i = 0; i < a.size(); ++i){
        a[i] += b[i];
    }
    normalize(a);
}
//a-=b 를 구현한다. a>= b를 가정한다.
void subFrom(vector<int>& a, vector<int>& b){
    for(int i = 0; i < a.size(); ++i){
        a[i] -= b[i];
    }
    normalize(a);
}


vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b.size(); ++j)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}
                                         
//vector a와 b는 거꾸로 뒤집혀서 들어온다.
vector<int> karatsuba(const vector<int>& a, const vector<int> & b){
    unsigned long an = a.size();
    unsigned long bn = b.size();
    
    if(an < bn) return karatsuba(b,a);
    if(an == 0 || bn == 0)return vector<int>();
    if(an<50) return multiply(a,b);
    unsigned long half = an/(unsigned long)2;

    //더 큰수의 절반의 뒷부분
    vector<int> a0(a.begin(),a.begin()+half);
    //더 큰수의 절반의 앞부분
    vector<int> a1(a.begin()+half,a.end());
    //더 작은수의 더 큰수 기준 절반의 뒷부분
    vector<int> b0(b.begin(),b.begin() + min(b.size(),half));
    //더 작은 수의 더 큰수 기준 절반의 앞부분
    vector<int> b1(b.begin() + min(b.size(),half),b.end());
    
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
int main(){
    vector<int> ret = karatsuba({1,2,3,4,5,6},{1,2,3,4,5,6});
    for(long long i = ret.size() - 1; i >= 0 ; --i){
        cout << ret[i];
    }
    cout << endl;
    return 0;
}
