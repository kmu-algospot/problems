#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 26
#define TO_NUMBER(X) X - 'a'

typedef struct TriNode {
	int count = 0;              
	bool terminate = false;     
	TriNode * child[MAX_LEN];
	TriNode() {
		memset(child, 0, sizeof(child));
	}
	~TriNode() {
		for (auto & node : child) {
			if (node) { delete node; }
		}
	}
	void insert(const char * key) {
		if (*key == 0) { this->terminate = true; }
		else {
			const int next = TO_NUMBER(*key);
			if (child[next] == NULL)  {
                child[next] = new TriNode(); 
            }
			child[next]->count++;
			child[next]->insert(key + 1);
		}
	}

	int find(const char * key, const int cnt) {

		const int next = TO_NUMBER(*key);
		if (*key == 0 || child[next] == NULL) return cnt - 1; 
		if (child[next]->count == 1) return cnt; 
		return child[next]->find(key + 1, cnt + 1);
	}

} Tri;

int solution(vector<string> words) {

	Tri * tri = new Tri();
	for (const auto word : words) {
		const auto c_word = word.c_str();
		tri->insert(c_word);
	}

	int answer = 0;
	for (const auto word : words) {
		const auto c_word = word.c_str();
		answer += tri->find(c_word, 1);
	}

    delete tri;
	return answer;
}
