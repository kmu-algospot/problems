#include <iostream>
#include <cstring>
using namespace std;


const int MAX = 501;
int cache[MAX] = {-1,};
int lis[MAX] = {0,};

int findLIS(int idx,int sizes){
        int &ret = cache[idx];
        if (ret != -1) return ret;
        ret = 1;
        for (int next = idx+1; next < sizes; next++)

               if (lis[idx] < lis[next])
                    ret = max(ret, findLIS(next,sizes) + 1);

        return ret;

}
int main(){
    int cases;
    cin>>cases;

    while(cases--){
        memset(cache,-1,sizeof(cache));
        memset(lis,0,sizeof(lis));
        int sizes;
        cin>>sizes;
        for(int idx=0; idx<sizes;idx++){
            cin>>lis[idx];
        }
        int maxLIS = 0;
        for(int idx=0; idx<sizes;idx++){
            maxLIS = max(maxLIS,findLIS(idx,sizes));
        }
        cout<<maxLIS<<"\n";
    }
}



