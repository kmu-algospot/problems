#include <iostream>
using namespace std;

int main(){
    int cases;
    cin>> cases;

    while(cases--){
        long long dp[101] = {0,};
        dp[1] = 1;
        dp[2] = 2;
    
        int num;
        cin>>num;
        if(num == 1){
            cout<<1<<"\n";
            continue;
        } else if(num == 2){
            cout<<0<<"\n";
            continue;
        }
        for(int i=3; i<=num; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        int ret =0;
        if(num %2 ==0){
            ret =1000000007+ dp[num] - ( dp[num/2] + dp[num/2 -1])%1000000007;
        } else{
            ret = 1000000007+dp[num] - dp[(num-1)/2]%1000000007;
        }
        cout<<ret % 1000000007<<"\n";
    }
}
