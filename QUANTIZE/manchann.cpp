#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int ArrayMax = 101;
const int GroupMax = 11;
int cache[ArrayMax][GroupMax] ={-1,};
int n,s;
int arr[ArrayMax] = {0,};

int average(int start,int end){
    double sum =0;
    for(int i=start; i<=end;i++){ 
        sum += arr[i];
    }
    double average = sum / end-start+1;
    average = floor(average+0.5);
    return int (average);
}

int quantization(int start,int group){
    int &ret = cache[start][group];
    if(ret != -1){
        return ret;
    }
    
    ret = 99999999;
    for(int i=start; i<n-s;i++){
        int quan = average(start,i);
        ret = min(ret, quantization(i,group-1)+quan);
    }
    return ret;
}

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        cin>>n>>s;
        for(int i=0; i< n; i++){
            cin>> arr[i];
        }
        sort(arr,arr+n);
        int minNum = 99999999;
        for(int i=0; i< n-s;i++){
            minNum = min(minNum,quantization(i,s));
        }
        cout<<minNum<<"\n";
    }
}
