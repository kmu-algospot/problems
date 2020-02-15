#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int memory[101][101];

bool check(string &pattern,string &s, int si,int pi) {
	if (!memory[pi][si]) {
		return false;
	}
	
	bool isMatch = false;
	if (pattern[pi] == '?' || pattern[pi] == s[si]) {
		if (pattern.length() - 1 == pi && s.length() - 1 == si) {
			isMatch = memory[pi][si] = true;
			return true;
		}
		isMatch = memory[pi][si] = check(pattern, s, si + 1, pi + 1);
		
	}
	else if (pattern[pi] == '*') {
		for (int i = si; i < s.length(); ++i) {
			if (pattern.length() - 1 == pi && s.length() - 1 == i) {
				isMatch = memory[pi][si] = true;
				return true;
			}
			memory[pi][i] = check(pattern, s, i, pi+1);
			if (memory[pi][i])
				isMatch = true;
		}
	}
	else {
		return false;
	}

	return isMatch;
}
bool comp(string a, string b) {
	return strcmp(a.c_str(), b.c_str()) < 0;
}
int main()
{
	int C;
	cin >> C;
	while (C--) {
		string pattern;
		int N;
		cin >> pattern;
		cin >> N;
		vector<string> inp;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			inp.push_back(s);
		}
		sort(inp.begin(), inp.end(), &comp);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= inp[i].length(); ++j) {
				for (int k = 0; k <= inp[i].length(); ++k) {
					memory[j][k] = -1;
				}
			}

			if (check(pattern, inp[i], 0, 0)) {
				cout << inp[i] << endl;
			}
		}
	}
}

