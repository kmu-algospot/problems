#include <iostream>
#include <string>

using namespace std;
int dx[] = {-1, -1, -1,  1, 1, 1,  0, 0};
int dy[] = {-1,  0,  1, -1, 0, 1, -1, 1};
int cases;
char board[5][5];
int num;
bool finder(string str,int x,int y){
    if(x>4|| y>4 || x<0 || y<0) return false;
    if(str.at(0) != board[x][y]){
        return false;
    }
    if(str.length() == 1) return true;  
    for(int direction = 0; direction < 8; ++direction) {    
        int X = x + dx[direction];
		int Y = y + dy[direction];  
		if(finder(str.substr(1),X, Y)) {
			return true;
		}
	}
	return false;
}
int main(){
    cin>>cases;
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++){
            cin>> board[i][j];
        }
    }
    cin>>num;
    while(cases--){
        for(int i=0;i<num;i++){
                string str;
                cin>> str;
                bool fin = false;
                for(int r =0; r<5;r++){
                    for(int c =0; c<5; c++){
                        if(finder(str,r,c)){
                            cout<<str<<" "<<"YES"<<"\n";
                            fin = true;
                            break;
                        }
                        }
                        if(fin) break;
                    }
                    if(!fin) cout<<str<<" "<<"NO"<<"\n";
            }
    }
}
