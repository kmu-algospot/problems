#include <iostream>
using namespace std;


int main(){
    int n,m;

    cin>>n>>m;

    int arr[100001] = {0,};
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int ret = 2000000000;
    int start, end =0;

    int sum = arr[0];
    int current_len =0;
    while(start <= end && end < n){
        if(sum < m){
            if(end < n){
                end ++;
                sum += arr[end];
            }
        } else if(sum >= m){
            current_len = end - start +1;
            if(ret > current_len){
                ret = current_len;
            } 

            if(start <= end){
                sum -= arr[start];
                start ++;
            }
        }
    }

    if(ret == 2000000000){
        cout<<0;
    } else{
        cout<<ret;
    }
}
