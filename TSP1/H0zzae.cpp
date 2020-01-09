#include <iostream>
using namespace std;
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)

double INF=9999.0;
double countryMatrix[8][8];
bool checkConnected[8]={false};
bool checkConnectedEachOther(int countryNumber){
    int count=0;
    for(bool c:checkConnected){
        if(c==true) {
            count++;
        }
    }
    if(count%2!=0) return true;
    return false;
}
double TSP(int countryNumber,bool allConnected, bool connectedEachOther){
    if(allConnected&&!connectedEachOther){
        connectedEachOther = true;   
    }
    if(connectedEachOther){
        int count =0;
        for(bool i:checkConnected){
            if(i==true) count++;
        }
        if(count==countryNumber) allConnected= true;
    }
    if(allConnected&&connectedEachOther){
        return 0;
    }
    if(!connectedEachOther){
        int count =0;
        for(bool i:checkConnected){
            if(i==true) count++;
        }
        if(count==countryNumber) allConnected = true;
    }
    double minValue = INF; 
    int minrow, mincol = 0;
    FOR(i,countryNumber){
        for(int j=i+1;j<countryNumber;j++){
            if(countryMatrix[i][j]<minValue){
                minValue = countryMatrix[i][j];
                minrow = i; mincol=j;
            }
        }
    }
    if(minValue==0){
        countryMatrix[minrow][mincol] = INF;
    }else if (minValue>0&&!allConnected){
        checkConnected[minrow]= true;
        checkConnected[mincol]= true;
        countryMatrix[minrow][mincol] = INF;
        connectedEachOther==true? connectedEachOther=true: connectedEachOther=checkConnectedEachOther(countryNumber);
    }
    return minValue+TSP(countryNumber,allConnected,connectedEachOther);
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int countryNumber;
        cin>>countryNumber;
        countryMatrix[8][8]={INF,};
        for(int i=0;i<countryNumber;i++){
            checkConnected[i] = false;
        }
        
        FOR(i,countryNumber){
            FOR(j,countryNumber){
                double distance;
                cin>>distance;
                if(distance!=0) {
                    countryMatrix[i][j] = distance;
                    countryMatrix[j][i] = distance;
                }
            }
        }
        bool allConnected=false;
        bool connectedEachOther=false;
        cout<<TSP(countryNumber,allConnected,connectedEachOther)<<endl;
    }
}