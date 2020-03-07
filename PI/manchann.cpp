#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int Max = numeric_limits<long long>::max();
int pi(string testcase,int size);
int level(string testcase,int size);

int main(){
    int cases;
    cin >>cases;
    while(cases--){
        string testcase;
        cin>> testcase;
        int minValue =Max;
        for(int i=0; i<3;i++){
            minValue = min(minValue,pi(testcase,i+3));
        }
        cout<<minValue<<"\n";
    }
    return 0;
}

int pi(string testcase,int size){
    int ret = Max;
    if(testcase.length()<3) return false;
    for (int i = 0; i < 3; i++)
        if(level(testcase,size)){
            ret = min(ret, pi(testcase.substr(size),i) + level(testcase.substr(size), size));
        }
    return ret;
}

int level(string testcase, int size){
    int distence;
    bool isEqual = true;
    bool isSequence = true;
    bool isZigzag = true;
    distence = testcase[0] - testcase[1];

    for(int i=0; i<size; i++){
        if(testcase[i] != testcase[i+1]){
            isEqual = false;
        }
        if(testcase[i] - testcase[i+1] != distence){
            isSequence = false;
        }
        if (testcase[i] != testcase[i % 2])
            isZigzag = false;
    }
    if(isEqual) return 1;
    if(isSequence&& abs(distence) == 1) return 2;
    if(isZigzag) return 4;
    if(isSequence) return 5;
    return 10;
}
