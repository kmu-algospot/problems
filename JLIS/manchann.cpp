#include <iostream>
#include <cstring>
using namespace std;

const int MIN = -9999;
const int MAX = 101;
int A[100],B[100] = {0,};
int cache[MAX][MAX] = {-1,};
int JLIS(int a, int b, int sizesA,int sizesB);

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        for(int i=0; i<MAX;i++){
            for(int j=0;j<MAX;j++){
                cache[i][j] = -1;
            }
        }
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        int sizesA,sizesB;
        cin>>sizesA;
        cin>>sizesB;
        int maxJLIS = 0;
        for(int i =0; i<sizesA;i++){
            cin>> A[i];
        }
        for(int i =0; i<sizesB;i++){
            cin>> B[i];
        }
        cout<<JLIS(-1,-1,sizesA,sizesB)<<"\n";
    }

}

int JLIS(int a, int b, int sizesA,int sizesB){
    int& ret = cache[a+1][b+1];
    if(ret != -1) return ret;
    ret = 0;
    int aNum = (a == -1 ? MIN : A[a]);
    int bNum =  (b == -1 ? MIN : B[b]);
    int maxNum = max(aNum,bNum);
    for(int i=a+1;i<sizesA;i++){
        if(maxNum < A[i] ){
            ret = max(ret,JLIS(i,b,sizesA,sizesB)+1);
        }
    }
    for(int i=b+1;i<sizesB;i++){
        if(maxNum < B[i] ){
            ret = max(ret,JLIS(a,i,sizesA,sizesB)+1);
        }
    }
    return ret;
}
