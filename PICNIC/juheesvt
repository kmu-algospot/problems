//
// Created by juheeSVT on 2019-11-25.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValid(vector<bool> &check, int n){
    int sum = 0;
    for ( int k = 0; k < n; k++ )
        sum += check[k];

    if ( sum == n ) {
        return true;
    }
    return false;
}

void initailize(vector<bool> &check, int n){
    for(int i = 0; i< n; i++) {
        check[i] = false;
    }
}

int picnic(vector< vector<int> > &pairs, int n){

    vector<bool> check(n);
    set<int> selected;
    set<int> tempSelected;
    set<int>::iterator iter;
    int cnt = 0;

    for ( int i = 0; i < pairs.size(); i++ ) {
        for ( int k = 0; k < n; k++ )
            check[k] = false;
        selected.clear();

        check[pairs[i][0]] = true;
        check[pairs[i][1]] = true;

        if ( isValid(check, n) ) {
            cnt++;
        }

        for ( int j = i+1; j < pairs.size(); j++ ) {

            // initialize check 때문에 필요
            check[pairs[i][0]] = true;
            check[pairs[i][1]] = true;

            if ( check[pairs[j][0]] == true || check[pairs[j][1]] == true ) {
                continue;
            }

            if ( check[pairs[j][0]] == false && selected.find(j) == selected.end()) {
                check[pairs[j][0]] = true;
            } else {
                continue;
            }

            if ( check[pairs[j][1]] == false && selected.find(j) == selected.end() ) {
                check[pairs[j][1]] = true;
            } else {
                continue;
            }

            //if ( check[pairs[j][0]] && check[pairs[j][1]] )
                tempSelected.insert(j);


            if ( isValid(check, n) ) {
                cnt++;
                for( iter = tempSelected.begin(); iter != tempSelected.end(); ++iter){
                    selected.insert(*iter);
                }
                tempSelected.clear();
                initailize(check, n);
                j = i+1;                // 다시 처음부터 검사
            }
        }
    }
    return cnt;
}

int main(){

    int caseNum;
    int n, m;

    scanf("%d", &caseNum);
    for (int i = 0; i < caseNum; i++) {
        scanf("%d %d", &n, &m);
        vector< vector<int> > pairs(m, vector<int>(2, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < 2; col++) {
                scanf("%d", &pairs[row][col]);
            }
        }
        printf("%d\n", picnic(pairs, n));
    }
}
