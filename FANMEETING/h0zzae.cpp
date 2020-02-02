#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size() + k)); 
    for (int i = 0; i< length; i++)
        a[i + k] += b[i]; 

}

//a-=b 구현, a>=b가정.
void subFrom(vector<int>& a, const vector<int>& b){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size()) + 1);

    for (int i = 0; i< length; i++)
        a[i] -= b[i];

}
vector<int> multiply(const vector<int> &a,const vector<int> &b){
    vector<int> c(a.size() + b.size() + 1, 0);  
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++)
            c[i+j]+=(a[i]*b[j]);
    }
    return c;
}
vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
    int an = a.size() , bn = b.size();
    // a가 b보다 짧을 경우 둘을 바꾼다.
    if(an < bn) return karatsuba(b, a);
    // 기저 사례 : a나 b가 비어 있는 정우
    if(an == 0 || bn == 0) return vector<int>();
    // 기저 사례 a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
    if(an <= 50) return multiply(a,b);
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
int hugCount(string &members, string &fans){
    int N = members.size(), M = fans.size();
    vector<int> a(N), b(M);
    for(int i=0;i<N;i++){
        a[i] = (members[i] =='M')? 1:0;
    }
    for(int i=0;i<M;i++){
        b[M-i-1]= (fans[i] =='M')?1:0;
    }
    vector<int> C = karatsuba(a,b);
    int count = 0;
    for(int i=N-1;i<M;i++){
        if(C[i] ==0)
            count++;
    }return count;
}

int main(){
    int test;
    cin>>test;
    string members, fans;
    while(test--){
        cin>>members>>fans;
        cout<<hugCount(members,fans)<<endl;
    }
}