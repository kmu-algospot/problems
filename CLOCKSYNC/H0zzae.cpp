#include <iostream>
#include <vector>
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)
using namespace std;

const int INF = 9999;
const int CLOCKNUM = 16;
const int BUTTONNUM = 10;
int clocksync(int clock[], int buttonIdx);
void pushButton(int clock[], int buttonIdx);
bool check12(int clock[]);
vector<vector<int>> button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});
int main(){
    int test;
    cin>>test;
    while(test--){
        int clock[CLOCKNUM];
        for(int i=0;i<CLOCKNUM;i++){
            int time;
            cin>>time;
            clock[i] = time;
        }
        int answer = clocksync(clock,0);
        if(answer==INF) cout<<-1<<endl;
        else cout<<answer<<endl;
    }return 0;
}
int clocksync(int clock[], int buttonIdx){
    if(buttonIdx==BUTTONNUM) return check12(clock)? 0 : INF;
    int ret = INF;
    for(int cnt=0;cnt<4;cnt++){
        ret = min(ret,cnt + clocksync(clock,buttonIdx+1));
        pushButton(clock,buttonIdx);
    }
    return ret;
}
void pushButton(int clock[], int buttonIdx){
    for(int i:button[buttonIdx]){
        clock[i]+=3;
        if (clock[i]==15) clock[i] = 3;
    }
}
bool check12(int clock[]){
    for(int i=0;i<CLOCKNUM;i++){
        if(clock[i]!=12) return false;
    }return true;
}
