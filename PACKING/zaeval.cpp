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
void tracking(int ti, int w, vector<vector<int>> & from, vector<int> & ret) {
    int nextW = from[ti][w];

    if (ti == 0)
        return;

    if (nextW == -1) {
        nextW = w;
    }
    else {
        ret.push_back(ti);
    }

    tracking(ti - 1, nextW, from, ret);
}
int main() {
    int C;
    cin >> C;
    while (C--) {
        int N, W;
        cin >> N >> W;

        vector<Thing*> things;
        vector<vector<int>> cache(2,vector<int>(W + 1, 0));
        vector<vector<int>> from(N+1,vector<int>(W + 1, -1));
        vector<int> carrior;

        things.push_back(NULL);

        for (int ti = 0; ti < N; ++ti) {
            Thing* thing = new Thing();
            cin >> thing->name >> thing->size >> thing->value;
            
            things.push_back(thing);
        }
        for (int ti = 1; ti <= N; ++ti) {
            for (int w = 0; w <= W; ++w) {
                cache[ti%2][w] = cache[!(ti%2)][w];
                if (w - things[ti]->size >= 0) {
                    if(cache[ti%2][w] < cache[!(ti%2)][w - things[ti]->size] + things[ti]->value){
                        from[ti][w] = w - things[ti]->size;
                        cache[ti%2][w] = cache[!(ti % 2)][w - things[ti]->size] + things[ti]->value;
                    }
                }
            }
        }

        tracking(N, W, from, carrior);

        sort(carrior.begin(), carrior.end());

        cout << cache[N%2][W] << " " << carrior.size() << endl;
        for (int i = 0; i < carrior.size(); ++i) {
            cout << things[carrior[i]]->name << endl;
        }
    }
    return 0;
}
