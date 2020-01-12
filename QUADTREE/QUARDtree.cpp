#include <iostream>
#include <string>

using namespace std;

//string ���� �ѱ�� �����ٱ�?
//�Լ��� ȣ��ɶ����� string ��ŭ �޸𸮰� ������ ���� string ũ�Ⱑ �����Ǿ��ִ°� �ƴϰ�//
//���۷����� �Ű������� �ذ��ϼ���  

string QuardTree(string Qt, int index) {
	string upLeft, upRight, downLeft, downRight;

	if (Qt[index] == 'b') {
		return string("b");
	}
	else if(Qt[index]=='w') {
		return string("w");
	}

	index++; //x�� ������ x���� ����..
	
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
