#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101];

int poly(int n, int from){
    int &ret = dp[n][from];
    if(n - from ==0){
        return 1;
    }
    if(ret != -1 ){
        return ret;
    }
    
    ret = 0;
    for(int i =1; i<=n - from; i++){
        int sum = i + from -1;
        sum *= poly(n-from,i);
        ret += sum % 10000000;
        ret %= 10000000;
    }

    return ret;
}

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        int n;
        cin>> n;
        int sum =0;
        memset(dp, -1, sizeof(dp));
        for(int i =1; i<=n; i++){
            sum += poly(n,i);
            sum %= 10000000;
        }
        cout << sum<<"\n";    
    }
}
