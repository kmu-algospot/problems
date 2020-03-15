#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int ArrayMax = 100;
const int GroupMax = 10;
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
    int ret = 0;
	for (int i = start; i <= end; i++) {
		int error = abs(average - arr[i]);
		ret += error * error;
	}

	return ret;
}

int quantization(int start,int group){
    if(start == n) return 0;
    if(group == 0) return 99999999;
    int &ret = cache[start][group];
    if(ret != -1){
        return ret;
    }
    
    ret = 99999999;
    for(int i=1; i<=n-start;i++){
        int quan = average(start,start+i-1);
        ret = min(ret, quantization(i+start,group-1)+quan);
    }
    return ret;
}

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        cin>>n>>s;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i< n; i++){
            cin>> arr[i];
        }
        sort(arr,arr+n);
        cout<<quantization(0,s)<<"\n";
    }
}
