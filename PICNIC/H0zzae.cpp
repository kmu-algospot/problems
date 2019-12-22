#include <iostream>
#include <string>
using namespace std;

int test;
int studentNum;
int studentMatrix[10][10]={0,};
int fairNum;
int findFair(bool check[]);
int main(){
    cin>>test;
    for(int t = 0;t<test;t++){
        cin>>studentNum>>fairNum;
        for(int i=0;i<studentNum;i++){
            for(int j =0;j<studentNum;j++){
                studentMatrix[i][j] = 0;
            }
        }
        int r,c;
        for(int i=0;i<fairNum;i++){
            cin >>r>>c;
            studentMatrix[r][c] = 1;
            studentMatrix[c][r] = 1;
        }
        bool check[10]={0,};
        cout<<findFair(check)<<endl;
    }
}
int findFair(bool check[]){
    int firstidx = -1;
    for(int idx = 0; idx<studentNum;idx++){
        if(!check[idx]) {
            firstidx = idx;
            break;
        }
    }
    if (firstidx == -1) return 1;
    int ret = 0;
    for(int fair = firstidx+1; fair<studentNum; fair++){
        if((studentMatrix[firstidx][fair]==1)&&!check[fair]){
            check[firstidx] = true;
            check[fair] = true;
            ret+=findFair(check);
            check[firstidx] = false;
            check[fair] = false;
        }
    }
    return ret;
}