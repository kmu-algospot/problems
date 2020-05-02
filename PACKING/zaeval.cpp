#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Thing {
	string name;
	int size;
	int value;
};
int main() {
	int C;
	cin >> C;
	while (C--) {
		int N, W, answer = 0, maxValue = -1;
		cin >> N >> W;

		vector<Thing*> things;
		vector<int> carrier(W+1,0);
		vector<set<int>> selected(W+1, set<int>());

		for (int ti = 0; ti < N; ++ti) {
			Thing* thing = new Thing();
			cin >> thing->name >> thing->size >> thing->value;
			
			things.push_back(thing);
		}
		for (int w = 0; w <= W; ++w) {
			for (int ti = 0; ti < N; ++ti) {
				if (w >= things[ti]->size 
					&& carrier[w] < carrier[w - things[ti]->size] + things[ti]->value 
					&& selected[w - things[ti]->size].find(ti) == selected[w - things[ti]->size].end()) {
					carrier[w] = carrier[w - things[ti]->size] + things[ti]->value;
					
					selected[w].clear();
					for(set<int>::iterator iter = selected[w - things[ti]->size].begin(); iter != selected[w - things[ti]->size].end();++iter){
						selected[w].insert(*iter);
					}

					selected[w].insert(ti);
					if (maxValue < carrier[w]) {
						maxValue = carrier[w];
						answer = w;
					}
				}
			}
		}
		cout << carrier[answer] << " " << selected[answer].size() << endl;
		for (set<int>::iterator iter = selected[answer].begin(); iter != selected[answer].end(); ++iter) {
			cout<<things[*iter]->name<<endl;
		}
		for (vector<Thing*>::iterator iter = things.begin(); iter != things.end();++iter) {
			delete* iter;
		}
	}
	return 0;
}
