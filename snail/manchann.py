#include <iostream>
using namespace std;

int n,m;
double cache[1001][2001] = {-1.0,};

double snail(int count, int height){
    double &ret = cache[count][height];


    if(ret != -1.0){
        return ret;
    }
    if(count == m){
        return height >= n;
    }

    return ret = (0.25 * snail(count+1,height+1)) + (0.75 * snail(count+1,height+2));
}

int main(){
    int cases;
    cin >> cases;

    while(cases--){
        cin>> n >> m;
        for(int i=0; i<1001; i++){
            for(int j=0; j<2001; j++ ){
                cache[i][j] = -1.0;
            }
        }
        cout.precision(11);
        cout<< snail(0,0) <<"\n";
    }

}

