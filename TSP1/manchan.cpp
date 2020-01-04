#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MAX_SIZE =8;
double relation[MAX_SIZE+1][MAX_SIZE+1];

double road(int current,double ret,vector<int> check);
int  main(){
    int cases;
    cin>>cases;
    cout.setf(ios::fixed); 
    cout.precision(10);
    while(cases--){
        int sizes;
        cin>>sizes;
        vector<int> check(sizes+1,0);
        for(int row =1; row<sizes+1;row++){
            check[row] = row;
            for(int col =1; col<sizes+1;col++){
                cin>> relation[row][col];
            }
        }
        double ans =0;
          printf("%.10lf\n", road(0, 0, check));
    }
}

double road(int current,double ret,vector<int> check){
    
    double compared =numeric_limits<double>::max(); ;
    if(check.size() == 1){
        return ret;
    }
      for(int i = 1; i < check.size(); i++){
        vector<int> erased = check;
        erased.erase(erased.begin() + i);
        compared = min(compared, road(check[i], ret + relation[current][check[i]], erased));
    }
    return compared;    
}
