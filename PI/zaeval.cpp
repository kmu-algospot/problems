#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 987654321;
enum DIFFICULTY { SAME = 1, INCREMENT = 2, REPEAT = 4, AP = 5, ETC = 10 };
int getCost(string& str) {

	int beforeGap = str[0] - str[1];
	unsigned int i;
	beforeGap = str[0] - str[1];
	for (i = 2; i < str.size(); ++i) {
		int nowGap = str[i - 1] - str[i];
		if (!(nowGap == beforeGap && nowGap == 0)) {
			break;
		}
	}
	if (i == str.size()) return SAME;

	beforeGap = str[0] - str[1];
	for (i = 2; i < str.size(); ++i) {
		int nowGap = str[i - 1] - str[i];
		if (!(nowGap == beforeGap && nowGap == 1 || nowGap == beforeGap && nowGap == -1)) {
			break;
		}
	}
	if (i == str.size()) return INCREMENT;

	beforeGap = str[0] - str[1];

	for (i = 2; i < str.size(); ++i) {
		int nowGap = str[i - 1] - str[i];
		if (-beforeGap != nowGap) {
			break;
		}
		beforeGap = nowGap;
	}
	if (i == str.size()) return REPEAT;

	beforeGap = str[0] - str[1];
	for (i = 2; i < str.size(); ++i) {
		int nowGap = str[i - 1] - str[i];
		if (nowGap != beforeGap) {
			break;
		}

	}
	if (i == str.size()) return AP;

	return ETC;


}
int pi(string& subStr, int nowIndex, vector<int>& cache) {
	if (cache[nowIndex] != MAX) {
		return cache[nowIndex];
	}
	if (subStr.size() < 3) {
		return MAX - 1;
	}
	for (int i = 3; i <= 5; ++i) {
		string nowStr = subStr.substr(0, i);
		int cost = getCost(nowStr);
		if (subStr.size() == i) {
			return cost;
		}
		string nextStr = subStr.substr(i);
		cache[nowIndex] = min(cache[nowIndex], pi(nextStr, nowIndex + i, cache) + cost);
	}
	return cache[nowIndex];
}
int main()
{
	int C;
	string inp;
	cin >> C;

	while (C--) {

		cin >> inp;
		vector<int> cache(inp.size(), MAX);

		cout << pi(inp, 0, cache) << endl;

	}
}
