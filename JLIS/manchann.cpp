#include <iostream>
#include <cstring>
using namespace std;


const int MAX = 101;
int A[100],B[100];
int cache[MAX][MAX] = {-1,};
int JLIS(int a, int b, int sizesA,int sizesB);

int main(){
    int cases;
    cin>> cases;
    while(cases--){
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
        for(int a=0; a<sizesA; a++){
            for(int b=0; b<sizesB;b++){
                maxJLIS = max(maxJLIS,JLIS(a,b,sizesA,sizesB));
            }
        }
        cout<<maxJLIS<<"\n";
    }

}

int JLIS(int a, int b, int sizesA,int sizesB){
    int& ret = cache[a][b];
    if(ret != 1) return ret;
    ret = 2;
    int maxNum = max(A[a],B[b]);
    for(int i=a+1;i<sizesA;i++){
        if(maxNum < A[i] ){
            ret = max(maxNum,JLIS(i,b,sizesA,sizesB)+1);
        }
    }
    for(int i=b+1;i<sizesB;i++){
        if(maxNum < B[i] ){
            ret = max(maxNum,JLIS(a,i,sizesA,sizesB)+1);
        }
    }
    cout<<ret;
    return ret;
}
