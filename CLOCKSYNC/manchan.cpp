#include <iostream>
using namespace std;

int relation[10][5] = {
    {0,1,2,-1,-1},
    {3,7,9,11,-1},
    {4,10,14,15,-1},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15,-1},
    {3,14,15,-1,-1},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int check[10] ={0,};
int clocks[16];
int ret;
int time_set(int time){
   int t = time%12;
   if(t ==0 ) return 12;
   return t;
}
bool checking(int clocks[16]){
    for(int k=0; k<16;k++){
        if(clocks[k] !=12)
            return false;
    }
    return true;
}
int search(int clocks[16],int index,int times){
   if(index+1 == 10){
      return ret;
    }
    check[index]+=times;
   
    for(int i =0; i<5;i++){
        if(clocks[relation[index][i]]== -1){
         break;
      }
        clocks[relation[index][i]] += check[index]*3;
      clocks[relation[index][i]]=time_set(clocks[relation[index][i]]);
    }
    if(checking(clocks)){
        for(int j =0; j<10;j++){
            ret += check[j];
        }
    }
   
   
   for(int i=0;i<4;i++){
      search(clocks,index+1,i);
   }
   
    return ret;
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int count =0;
        clocks[16] ={0,};
        for(int i=0;i<16;i++){
            cin>>clocks[i];
        }
      
        if(clocks[14] != clocks[15]){
           cout<<"-1"<<"\n";
            continue;
        }
      
        for(int i=0; i<4;i++){
            count+=search(clocks,0,i);
            check[10] ={0,};
         ret =0;
        }
        cout<<count<<"\n";
    }
}
