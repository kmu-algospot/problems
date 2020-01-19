#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int current_max;
int finder(vector<int> fence);
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int sizes;
        cin>>sizes;
        vector<int> fence(sizes);
        for(int i=0; i<sizes;i++){
            cin>> fence[i];
        }
        current_max =0;
        cout<<finder(fence)<<"\n";
    }
}
int finder(vector<int> fence){
    int minElement = *min_element(fence.begin(), fence.end());
    if(minElement != 0&&fence.size() !=0){
        
     int mx = minElement*fence.size();
    current_max = max(mx,current_max);
    if(fence.size() == 1){
         return current_max;
    }
    for(int i=0; i<fence.size(); i++){
        if(fence[i] == minElement){
            vector<int> copy_first;
            vector<int> copy_second;
            copy_first.assign(fence.begin()+i+1,fence.end());
            copy_second.assign(fence.begin(),fence.begin()+i+1);
            finder(copy_first);
            finder(copy_second);
        }   
            
    }
    }
  
}
