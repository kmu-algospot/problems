//  BOGGLE
//  c++
//
//  Created by 홍승의 on 2019/12/1.
//  Copyright © 2019 홍승의. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 5;
const int DIRECT_MAX = 8;
const int DELTA_X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DELTA_Y[] = {0, 1, -1, 1, -1, 0, 1, -1};

bool hasWord(int x, int y,int level,string &word,vector<string> &map){

    if(x >= MAX_SIZE || y >= MAX_SIZE || x < 0 || y < 0){
        return false;
    }
    if(level >= word.length()){
        return true;
    }
    if(map[y][x] != word[level]){
        return false;
    }
    
    for(int direct = 0; direct < DIRECT_MAX; ++direct){
        if(hasWord(x+DELTA_X[direct],y+DELTA_Y[direct],level+1,word,map))
            return true;
    }

    return false;
}
int main(){
    int C;
    int N;
    
    scanf("%d",&C);
    for(int ci = 0; ci<C; ++ci){
        vector<string> in;
        for(int row = 0; row < MAX_SIZE; ++row ){
            string temp;
            cin >> temp;
            in.push_back(temp);
        }
        scanf("%d",&N);
        for(int wi = 0; wi < N; ++wi){
            string word;
            cin >> word;
            bool noCheck = true;
            for(int row = 0; row<MAX_SIZE && noCheck;++row){
                for(int col = 0; col<MAX_SIZE && noCheck; ++col){
                    if(hasWord(col,row,0,word,in)){
                        printf("%s YES\n",word.c_str());
                        noCheck=false;
                    }
                }
            }
            if(noCheck)
                printf("%s NO\n",word.c_str());
                
        }
        
    }
    
    return 0;
}
