// 백준 4673

#include <iostream>
using namespace std;

int main() {

    int selfNumber[10000] = {0,};
    int targetNumber, currentNumber;

    for (int i = 1; i < 10000; i++) {
        targetNumber = 0;
        currentNumber = i;

        bool isOver = false;
        if (currentNumber / 10 != 0) {
            while (currentNumber / 10 != 0) {
                targetNumber += currentNumber % 10;
                currentNumber /= 10;
                if (targetNumber > 10000) {
                    isOver = true;
                    break;
                }
            }
            if(isOver)
                break;
            targetNumber += currentNumber + i;

        }
        else {
            targetNumber += 2*i;
        }
        if(targetNumber < 10000){
            if (selfNumber[targetNumber - 1] == 0) {
                selfNumber[targetNumber - 1] = 1;
            }
        }
    }

    for(int i = 0; i<9999; i++){
        if( selfNumber[i] == 0)
            cout << i+1 <<endl;
    }

}
