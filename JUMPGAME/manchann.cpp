#include <iostream>
#include <cstring>
using namespace std;

int size;
int board[101][101] ={-1};
int cache[101][101];
int jumpgame(int x,int y);

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        memset(cache,-1,sizeof(cache));
        cin>>size;
        for(int x =0; x<size;x++){
            for(int y =0; y<size;y++){
                cin>> board[x][y];
            }
        }
        if(jumpgame(0,0) == true){
            cout<< "YES"<<"\n";
        } else{
            cout<<"NO" <<"\n";
        } 
    }
}

int jumpgame(int x,int y){
    if(x >=size || y>=size)
        return 0;
    if(x == size-1 && y == size-1)
        return 1;
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    return ret = jumpgame(x+board[x][y],y) || jumpgame(x,y+board[x][y]);
}
