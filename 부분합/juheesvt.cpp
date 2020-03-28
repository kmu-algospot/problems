#include <iostream>
#include <algorithm>

using namespace std;

int numArr[100000];

int main() {

    int length, minSum;
    cin >> length >> minSum;

    for (int i = 0; i < length; i++) {
        cin >> numArr[i];
    }

    int sum = numArr[0], result = length + 1;
    int l =0, r =0;

    while ( l <= r && r < length ) {
        if ( sum < minSum) {
            r++;
            sum += numArr[r];
        }
        else {
            result = min(result, r-l+1);
            sum -= numArr[l];
            l++;
        }
    }

    cout << (result > length ? 0 : result) ;
}

