#include<iostream>
#include<vector>
using namespace std;

int main(){
  int C, N;
  cin >> C;
  while(C--){
  	cin >> N;
	int temp;
	vector<int> arr;
	vector<int> dp;
	int answer = 0;
	for(int i = 0; i < N; ++i){
		cin >> temp;
	  	arr.push_back(temp);
	  	dp.push_back(0);
	  	int max = 0;
	  	for(int j = 0; j < arr.size() - 1; ++j){
			if(temp > arr[j] && max < dp[j]){
				max=dp[j];
			}
		}
	  	dp[arr.size()-1] = max+1;
	  	if(answer < dp[arr.size()-1]){
			answer = dp[arr.size()-1];
		}
	  }
	cout << answer <<endl;
  }
  
  return 0;
}
