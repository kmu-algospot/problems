#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int Max = 99999999;
int pi(string testcase,int size,int idx);
int level(string testcase,int size);
int cache[10001] = {-1,};

int main(){
    int cases;
    cin >>cases;
    while(cases--){
        string testcase;
        cin>> testcase;
        memset(cache,-1,sizeof(cache));
        int minValue =Max;
        for(int i=0; i<3;i++){
            minValue = min(minValue,pi(testcase,i+3,0));
        }
        cout<<minValue<<"\n";
    }
    return 0;
}

int pi(string testcase,int size,int idx){
    int ret = cache[idx];
    if(ret != -1) return ret;
    ret = Max;
    for (int i = 0; i < 3; i++)
        if(level(testcase.substr(idx,i+3),i+3)){
            if(idx+i+3 <=testcase.length()){
                ret = min(ret, pi(testcase,i+3,idx+i+3) + level(testcase.substr(idx,i+3), i+3));
            }
        }
    return ret;
}

int level(string testcase, int size){
    if(testcase.length()<3) return false;
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
