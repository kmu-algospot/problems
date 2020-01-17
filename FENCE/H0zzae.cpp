#include <iostream>
#include <vector>
using namespace std;

const int MaxHeight = 10000;
int solve(int left,int right);
vector<int> Fence;

int main(){
    int test;
    cin >>test;
    for(int t = 0;t<test;t++){ //원래 while(test--)이었는데 밑의 for문이 안돌아가서 for문으로 바꿈. 왜지?
        int fenceNumber;
        cin >>fenceNumber;
        for(int i =0;i<fenceNumber;i++){ 
            int input;
            cin>>input;
            Fence.push_back(input);
        }
        cout<<solve(0,fenceNumber-1)<<endl; //idx니까 fenceNumber-1.
        Fence.clear();
    }
}
int solve(int left,int right){
    if(left==right) return Fence[left]; //울타리수가 하나일때
    int mid = (left+right)/2;  //중간값구하기
    int ret = max(solve(left,mid),solve(mid+1,right)); //오른쪽이랑 왼쪽의 각각큰값비교.
    int low = mid, hi = mid+1;  // 오른쪽이랑 왼쪽에 걸쳐서 있는 사각형 조사.
    int height = min(Fence[low],Fence[hi]);  //작은 값부터 조사.
    ret = max(ret, height*2); // 너비가 2인 중간의 사각형 체크.
    while(left<low||hi<right){  // fence를 끝까지 다 포함할때까지.
        if( hi<right &&(low == left||Fence[low-1]<Fence[hi+1])){  // 오른쪽이 높을때
            height = min(height, Fence[++hi]);
        }else{   //왼쪽이 더 높을때.
            height = min(height, Fence[--low]);
        }  
        ret = max(ret, height*(hi-low+1));   // (hi-low+1)은 너비.
    }
    return ret;
}