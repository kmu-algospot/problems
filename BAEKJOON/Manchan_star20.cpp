#include <iostream>
using namespace std;


int print(int star_idx,int num){
	if(star_idx %2 == 0){
		for(int star =0; star < num; star++){
			cout<<"*"<<" ";
		}	
		cout<<"\n";
		return 0;
	} else{
		for(int star =0; star < num; star++){
			cout<<" "<<"*";
		}	
		cout<<"\n";
		return 0;
	}
}

int main(){

   	int num;
	cin	>> num;
	for(int star_idx =0; star_idx< num; star_idx++){
		print(star_idx,num);
	}	
    return 0;

}