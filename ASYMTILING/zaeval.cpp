#include <iostream>

using namespace std;

const int MOD = 1000000007;
int cache[101]={0,1,2};

int main() {
    
    int C, N;
    
    cin >> C;
    for(int i=3; i<=100; ++i){
        cache[i] = (cache[i-1] + cache[i-2])%MOD;
    }
    while(C--){
        cin >> N;
       
        if(N<=2){
            cout << 0 << endl;
        }
        else{
            if(N%2){
                cout << cache[N] - cache[N/2] << endl;
            }
            else{
                int asym = cache[N] - (cache[N/2-1] + cache[N/2])%MOD;
                if(asym < 0 )asym += MOD;
                cout << asym << endl;
            }
        }
    }
    
    return 0;
}
