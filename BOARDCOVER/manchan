#include <iostream>
using namespace std;

int W,H;
int count;
int shapes[4][3][2] = {
        {{0,0},{1,0},{0,-1}},
        {{0,0},{1,0},{1,-1}},
        {{0,0},{0,-1},{1,-1}},
        {{0,0},{0,-1},{-1,-1}}
    };
char map[21][21];
int checking(int x, int y){
    for (int i = 0; i < 4; i++){
        int check = 1;
        for (int j = 1; j < 3; j++){
            if (x + shapes[i][j][0] >= H || y + shapes[i][j][1] < 0 
            || y + shapes[i][j][1] >= W 
            || map[x + shapes[i][j][0]][y + shapes[i][j][1]] != '.'){
                check = 0;
                break;
            }
        }
        if (check){
            for (int j = 0; j < 3; j++) {
                map[x + shapes[i][j][0]][y + shapes[i][j][1]] = '#';
            }
            int result = 0;
            for (int i = x; i < H && result==0; i++){
                for (int j = 0; j < W; j++){
                    if (map[i][j] == '.'){
                        checking(i, j);
                        result = 1;
                        break;
                    }
                }
            }
            if (result == 0){
                count++;
                for (int j = 0; j < 3; j++){
                    map[x + shapes[i][j][0]][y + shapes[i][j][1]] = '.';
                }
            }
            for (int j = 0; j < 3; j++){
                map[x + shapes[i][j][0]][y + shapes[i][j][1]] = '.';
            }
        }
    }
}

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        count =0;
        char map[21][21] = {0,};
        cin >>H >> W;
        int white_count =0;
        int ret =0;
        for(int h =0; h < H; h++){
            for(int w =0; w < W; w++){
                cin>> map[h][w];
                if(map[h][w] == '.'){
                    white_count++;
                }
            }
        }
        if(white_count%3 !=0){
            cout<<"0"<<"\n";
            continue;
        }
         for(int h =0; h < H && ret ==0 h++){
            for(int w =0; w < W; w++){
                cin>> map[h][w];
                if(map[h][w] == '.'){
                    checking(h, w);
                    ret = 1;
                    break;
                }
            }
        }
        cout<<count<<"\n";
    }
}
