//
// Created by juheeSVT on 2020-03-21.
//

//
// Created by juheeSVT on 2020-03-21.
//

#include <iostream>

using namespace std;
const int MAX = 100;
int memory[100];

int main() {

    int testCase, number;
    cin >> testCase;

    while(testCase--) {
        cin >> number;

        if (number == 1)   cout << 1 <<endl;
        else if (number == 2)   cout << 2 <<endl;
        else {
            long long a,b,c;
            for (int i = 0; i < number-2; i++) {
                if ( i == 0 ) {
                    a =1 ,b =2, c = a+b;
                }
                else {
                    a = b % 1000000007;
                    b = c % 1000000007;
                    c = (a + b) % 1000000007;
                }
            }
            cout << c << endl;
        }
    }
}
