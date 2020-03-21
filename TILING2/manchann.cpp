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
            cout<<2<<"\n";
            continue;
        }
        for(int i=3; i<=num; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        cout<<dp[num] % 1000000007<<"\n";
    }
}
