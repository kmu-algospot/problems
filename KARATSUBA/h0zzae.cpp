#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void normalize(vector<int> &num){
    num.push_back(0);
    for(int i=0;i<num.size()-1;i++){
        if(num[i]<0){ //음수가 될 수가 있나?
            int borrow = (abs(num[i])+9)/10; 
            num[i+1]-=borrow;
            num[i] +=borrow*10;
        }
        else
        {
            num[i+1]+=num[i]/10; 
            num[i] %=10;   
        }
    }
    while(num.size()>1 && num.back()==0)
        num.pop_back();

}
//a+=b*(10^k)를 구현한다  b가더큼.
void addTo(vector<int>& a, const vector<int>& b, int k){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size() + k)); // 총 자릿수만큼 a resize 원래 a보다 길어지면 길어진 만큼은 0으로 초기화.
    for (int i = 0; i< length; i++)
        a[i + k] += b[i]; 

    normalize(a);
}

//a-=b 구현, a>=b가정.
void subFrom(vector<int>& a, const vector<int>& b){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size()) + 1);

    for (int i = 0; i< length; i++)
        a[i] -= b[i];

    normalize(a);
};
vector<int> multiply(const vector<int> &a,const vector<int> &b){
    vector<int> c(a.size() + b.size() + 1, 0);  //0으로 초기화된 a.size()+b.size()+1의 크기를 가진 vector생성.
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++)
            c[i+j]+=(a[i]*b[j]);
    }
    normalize(c);
    return c;
};
vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {// 두 긴 정수의 곱을 반환한다.
    int an = a.size() , bn = b.size();
    // a가 b보다 짧을 경우 둘을 바꾼다.
    if(an < bn) return karatsuba(b, a);
    // 기저 사례 : a나 b가 비어 있는 정우
    if(an == 0 || bn == 0) return vector<int>();
    // 기저 사례 a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
    if(an <= 5) return multiply(a,b);
    int half = an/2;
    // a와 b를 밑에서 half 자리와 나머지로 분리한다
    vector<int> a0(a.begin() , a.begin() + half);   // a0이 a1보다 더 작은수. 왜 이렇게하면 나눠지는건가?
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin() , b.begin() + min<int>(b.size() ,half));
    vector<int> b1(b.begin() + min<int>(b.size() , half) , b.end());
    // z2 = a1 * b1
    vector<int> z2 = karatsuba(a1, b1);
    //z0 = a0 * b0
    vector<int> z0 = karatsuba(a0, b0);
    // a0 = a0 + a1; b0 = b0 + b1
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    // z1 = (a0 * b0) - z0 -z2;
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

int main(){
    vector <int> a, b, result;
    string number;
    cin>>number;
    for(int i=number.size()-1;i>=0;i--){
        a.push_back(number[i]-'0');  // char to int 간단한 방법
    }
    cin>>number;
    for(int i=number.size()-1;i>=0;i--){
        b.push_back(number[i]-'0');
    }
    result = karatsuba(a,b);
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }cout<<endl;
}