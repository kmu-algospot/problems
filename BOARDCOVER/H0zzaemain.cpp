#include <iostream>
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)
using namespace std;

int test,h,w;
int board[20][20];
const int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};
bool set(int y, int x, int type, int delta){
    bool ok = true;
    FOR(i,3){
        const int ny = y+coverType[type][i][0];
        const int nx = x+coverType[type][i][1];
        if(ny<0 || ny>=h || nx<0 || nx>=w)
            ok = false;
        else if((board[ny][nx] += delta)>1)
            ok = false;
    }
    return ok;
}
int cover(){
    int y = -1,x = -1;
    FOR(i,h){
        FOR(j,w){
            if(board[i][j] == 0){
                y = i;
                x = j;
                cout<<i<<"y"<<j<<"x"<<"\n";
                break;
            }
        }if(y!=-1) break;
    }
    if(y==-1) return 1;
    int ret =0;
    FOR(type,4){
        if(set(y,x,type,1))
            ret+=cover();
        set(y,x,type,-1);
    }
    return ret;
}
int main(){
    cin>>test;
    char input[20];
    FOR(t,test){
        cin>>h>>w;
        FOR(i,h){
            cin>>input;
            FOR(j,w){
                board[i][j] = input[w]=='#'?1:0;
            }
        }
        cout<<cover()<<endl;   
    }
    return 0;
}