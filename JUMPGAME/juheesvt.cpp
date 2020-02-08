
#include <iostream>
#include <string.h>

using namespace std;


const int MAX = 100;
int map[MAX][MAX];
int cache[MAX][MAX];

int jumpGame(int y, int x, int mapSize) {

	if (y >= mapSize || x >= mapSize)
		return 0;

	if (y == mapSize-1 && x == mapSize-1)
		return 1;

	if (cache[y][x] != -1)
		return cache[y][x];

	int jump = map[y][x];

	return cache[y][x] = (jumpGame(y + jump, x, mapSize) || jumpGame(y, x + jump, mapSize));
}

int main() {

	int testCase, mapSize;

	scanf("%d", &testCase);

	while (testCase--) {
		
		memset(cache, -1, sizeof(cache));
		scanf("%d", &mapSize);
		for (int r = 0; r < mapSize; r++) {
			for (int c = 0; c < mapSize; c++) {
				scanf("%d", &map[r][c]);
			}
		}
		if (jumpGame(0, 0, mapSize))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
