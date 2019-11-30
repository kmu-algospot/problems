//
//  PICNIC.cpp
//  c++
//
//  Created by 홍승의 on 2019/12/01.
//  Copyright © 2019 홍승의. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
struct FriendInfo{
    int f1;
    int f2;
};
bool check[10];
int n;
int countPairs(int idx, vector<FriendInfo> &friendsInfos,int pairNum){
    FriendInfo now = friendsInfos[idx];
    if(check[now.f1] || check[now.f2])
        return 0;
    if(pairNum == n/2)
        return 1;
    
    check[now.f1] = true;
    check[now.f2] = true;
    
    int count = 0;
    for(int nextIdx=idx+1; nextIdx<friendsInfos.size(); ++nextIdx){
        count+=countPairs(nextIdx,friendsInfos,pairNum+1);
    }
    
    check[now.f1] = false;
    check[now.f2] = false;
    
    return count;
}
int main(){
    int C,m;
    
    scanf("%d",&C);
    for(int ci = 0; ci < C; ++ci){
        scanf("%d %d",&n,&m);
        vector<FriendInfo> friendsInfos;
        for(int pi = 0; pi < m; ++pi){
            FriendInfo temp;
            scanf("%d %d",&temp.f1,&temp.f2);
            friendsInfos.push_back(temp);
        }
        int count = 0;
        for(int pi = 0; pi < m; ++pi){
            count += countPairs(pi, friendsInfos, 1);
        }
        printf("%d\n",count);
    }
    return 0;
}
