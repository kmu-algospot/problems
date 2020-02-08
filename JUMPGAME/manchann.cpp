#include <iostream>
using namespace std;


int board[101][101] ={-1};
bool jumpgame(int x,int y,int size);

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        int size;
        cin>>size;
        for(int x =0; x<size;x++){
            for(int y =0; y<size;y++){
                cin>> board[x][y];
            }
        }
        if(jumpgame(0,0,size) == true){
            cout<< "YES"<<"\n";
        } else{
            cout<<"NO" <<"\n";
        } 
    }
}

bool jumpgame(int x,int y,int size){
    if(x >=size || y>=size)
        return false;
    if(board[x][y] == 0)
        return true;
    return jumpgame(x+board[x][y],y,size) || jumpgame(x,y+board[x][y],size);
}
