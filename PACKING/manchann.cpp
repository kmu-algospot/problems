#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int cnt;
int capacity;
int cache[1001][101] = {-1,};
int weight[101] = {0,};
int dense[101] = {0,};
string name[101];

int packing(int capacity, int item){
    if(item == cnt){
        return 0;
    } 
    int &ret = cache[capacity][item];
    if(ret != -1) return ret;

    ret = packing(capacity,item+1);

    if(capacity >= weight[item]){
        ret = max(ret, packing(capacity - weight[item], item+1) + dense[item]);
    }
    return ret;
}

void find_answer(int capacity, int item, vector<string>& picked){
    if(item == cnt) return;
    if(packing(capacity,item) == packing(capacity, item +1)){
        find_answer(capacity, item+1, picked);
    } else{
        picked.push_back(name[item]);
        find_answer(capacity - weight[item], item+1,picked);
    }
}

int main(){
    int cases;
    cin>> cases;
    while(cases--){
        cin>> cnt;
        cin>> capacity;
        vector<string> picked;
        for(int i=0; i<cnt; i++){
            cin>> name[i];
            cin>> weight[i];
            cin>> dense[i];
        }

        memset(cache, -1, sizeof(cache));
        find_answer(capacity, 0, picked);
        cout << packing(capacity, 0) << " " << picked.size() << "\n";
        for (int j = 0; j < picked.size(); j++)
            cout << picked[j] << "\n";
    }
}
