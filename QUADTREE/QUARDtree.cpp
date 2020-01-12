#include <iostream>
#include <string>

using namespace std;

//string 으로 넘기면 안좋다그?
//함수가 호출될때마다 string 만큼 메모리가 잡히기 때문 string 크기가 고정되어있는게 아니고//
//레퍼런스로 매개변수로 해결하세요  

string QuardTree(string Qt, int index) {
	string upLeft, upRight, downLeft, downRight;

	if (Qt[index] == 'b') {
		return string("b");
	}
	else if(Qt[index]=='w') {
		return string("w");
	}

	index++; //x가 나오면 x다음 부터..
	
	upLeft = QuardTree(Qt, index);
	index += upLeft.length();
	upRight = QuardTree(Qt, index);
	index += upRight.length();
	downLeft = QuardTree(Qt, index);
	index += downLeft.length();
	downRight = QuardTree(Qt, index);
	
	return string("x") + downLeft + downRight + upLeft + upRight;
}


int main() {
	int n;
	cin >> n ;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		cout << QuardTree(st, 0) << endl;
	}

}
