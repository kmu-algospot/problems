#include <iostream>
#include <queue>
using namespace std;
int n,board[100][100];
int cache [100][100];
class Pos{
public:
    int x;
    int y;
    Pos(int x,int y){
        this->x = x;
        this->y = y;
    }
};
int jump2(int y, int x) {
    queue<Pos *> q;
    q.push(new Pos(x,y));
    while(!q.empty()){
        Pos *now = q.front();
        q.pop();
        cache[now->y][now->x] = 1;
        int jumpValue = board[now->y][now->x];
        for(int i = 0;i<n;++i){
            for(int j = 0; j<n;++j){
                cout<<(cache[i][j]==1)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        if(now->y + jumpValue < n && cache[now->y+jumpValue][now->x] == -1){
            q.push(new Pos(now->x,now->y+jumpValue));
        }
        if(now->x + jumpValue < n && cache[now->y][now->x+jumpValue] == -1){
            q.push(new Pos(now->x+jumpValue,now->y));
        }
        delete now;
    }
    return cache[n-1][n-1] == 1;
}
int main(){
    int C;
    scanf("%d",&C);
    while(C--){
        scanf("%d",&n);
        for(int i = 0; i < n;++i){
            for(int j =0;j < n;++j){
                scanf("%d",&board[i][j]);
                cache[i][j] = -1;
            }
        }
        cout << ((jump2(0,0))?("YES"):("NO")) << endl;
    }
    return 0;
}
