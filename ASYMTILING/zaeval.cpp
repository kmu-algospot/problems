#include <iostream>

using namespace std;

const int MOD = 1000000007;
int cache[101];
int tiling(int width){
    if(width <= 1)return width;
    if(cache[width] != -1) return cache[width];
    return cache[width] = (tiling(width-2) + tiling(width-1)) % MOD;
}
int main() {
    
    int C, N;
    
    cin >> C;
    
    while(C--){
        cin >> N;
        for(int i=0; i<=N;++i){
            cache[i] = -1;
        }
        if(N<=2){
            cout << 0 << endl;
        }
        else{
            if(N%2){
                cout << tiling(N) - tiling(N/2) << endl;
            }
            else{
                cout << tiling(N) - tiling(N/2-1) << endl;
            }
        }
    }
    
    return 0;
}
