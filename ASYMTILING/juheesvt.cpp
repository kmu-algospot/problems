
#include <iostream>

using namespace std;
const int MOD = 1000000007;
int memory[101] = {0,1,2};

int main() {

    int testCase, number;
    cin >> testCase;

    while(testCase--) {
        cin >> number;

        if (number == 1 || number == 2)   cout << 0 << endl;
        else {
            for (int i = 0; i < number-2; i++) {
                memory[i+3] = (memory[i+1] + memory[i+2])%MOD;
            }
            if ( number % 2 == 0 ) {
                int result = memory[number] - (memory[number/2] + memory[(number-2)/2]) % MOD;
                cout <<  ((result < 0) ? result + MOD : result) << endl;
            }
            else {
                cout << memory[number] - memory[number/2] << endl;
            }
        }
    }
}
