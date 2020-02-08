#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int board[100][100];
int cache[100][100];
int jump(int y, int x, int size){
    if(y==size-1&&x==size-1) return 1;
    if(y>=size || x>=size) return 0;
    if(cache[y][x]!=-1){
        return cache[y][x];
    }
    int &ret = cache[y][x];
    if(ret!=-1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y+jumpSize,x,size)||jump(y,x+jumpSize,size));
}

int main()
{
    fill(&board[0][0],&board[99][100],-1);
    int test;
    cin>>test;
    while(test--){
        int size;
        cin>>size;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cin>>board[i][j];
                cache[i][j] = -1;
            }
        }
        if (jump(0,0,size)==1) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    
    return 0;
}
