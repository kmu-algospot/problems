#include <iostream>
#include <string>
#include <tuple>
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)
using namespace std;


int test;
const int Max_BoardSize = 5;
char board[Max_BoardSize][Max_BoardSize];
int wordcase;
const int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0 };
const int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1 };
string boggle(int wc, string findWord);
tuple<int,int> checkExist(int pr, int pc, char findChar);
int main(){
    cin>>test;
    FOR(tc,test){
        FOR(r,Max_BoardSize){
            FOR(c,Max_BoardSize){
                cin>>board[r][c];
            }
        }
        string wordArr[10] = {"0",};
        cin>>wordcase;
        FOR(wc,wordcase){
            cin>>wordArr[wc];
            cout<<wordArr[wc]<<" "<<boggle(wc,wordArr[wc])<<endl;
        }
    }
}
string boggle(int wc, string findWord){
    int pr,pc =0;
    FOR(r,Max_BoardSize){
        FOR(c,Max_BoardSize){
            if (board[r][c] == findWord.front()){
                pr = r;
                pc = c;
            }
        }
    }
    for(int idx =1; idx<findWord.size();idx++){
        tuple<int,int> rc;
        rc = checkExist(pr, pc, findWord.at(idx));
        if (get<0>(rc)!=-1){
            pr = get<0>(rc);
            pc = get<1>(rc);
        }
    }
    if(board[pr][pc]==findWord.at(findWord.size()-1)) return "YES";
    else return "NO";

}

tuple<int,int> checkExist(int pr, int pc, char findChar){
    FOR(direction,8){
        if((pr-dr[direction]>=0&&pr-dr[direction]<5)&&(pc-dc[direction]>=0&&pc-dc[direction]<5)){
            if(board[pr-dr[direction]][pc-dc[direction]]==findChar){
                return make_tuple(pr-dr[direction],pc-dc[direction]);
            }
        }else return make_tuple(-1, -1);
    }return make_tuple(-1, -1);
}