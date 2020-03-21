//
// Created by juheeSVT on 2020-03-21.
//

#include <iostream>

using namespace std;

struct Matrix {
    unsigned long matrix[2][2];
};

Matrix multiplication(Matrix a, Matrix b);
Matrix matrixFunc(Matrix M, int number);

int main() {

    int testCase, number;
    cin >> testCase;

    Matrix f1 = {1,1,1,0};

    while(testCase--) {
        cin >> number;
        cout << matrixFunc(f1, number).matrix[0][1]<< endl;
    }

}

Matrix multiplication(Matrix a, Matrix b) {

    Matrix ret;

    ret.matrix[0][0] = (a.matrix[0][0] * b.matrix[0][0] + a.matrix[0][1] * b.matrix[1][0]) ;
    ret.matrix[0][1] = (a.matrix[0][0] * b.matrix[0][1] + a.matrix[0][1] * b.matrix[1][1]) ;
    ret.matrix[1][0] = (a.matrix[1][0] * b.matrix[0][0] + a.matrix[1][1] * b.matrix[1][0]) ;
    ret.matrix[1][1] = (a.matrix[1][0] * b.matrix[0][1] + a.matrix[1][1] * b.matrix[1][1]) ;

    return ret;
}

Matrix matrixFunc(Matrix M, int number) {

    if ( number > 1) {
        M = matrixFunc(M, number / 2);
        M = multiplication(M, M);

        if (number % 2 != 0) {
            Matrix F1 = {1, 1, 1, 0};
            M = multiplication(M, F1);
        }
    }
    return M;
}
