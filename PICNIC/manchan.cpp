#include <iostream>
#include <cstring>

using namespace std;

int n, m;

bool friends[10][10];

int countPair(bool taken[10]){
    int firstpoint = -1;
    for (int i =0; i<n;i++){
        if(!taken[i]){
            firstpoint = i;
            break;
        }
    }

    if(firstpoint == -1){
        return true;
    }

    int ret =0;

    for(int i=firstpoint +1; i<n; i++){
        if(!taken[i] && friends[firstpoint][i]){
            taken[firstpoint] = taken[i] = true;
            ret += countPair(taken);
            taken[firstpoint] = taken[i] = false;
        }
    }

    return ret;
}
    
int main(){
    int cases;
    cin >> cases;

    while (cases--){
        cin >> n >> m;

        memset(friends,0,sizeof(friends));
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            friends[a][b] = friends[b][a] = true;
        }

        bool taken[10];
        memset(taken,0,sizeof(taken));
        cout<<countPair(taken) << endl;
    }
    return 0;
}