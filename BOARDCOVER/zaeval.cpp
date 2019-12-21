#include<iostream>
#include<vector>

const char BLACK = '#';
const char WHITE = '.';

const int BLOCK_SHAPE[4][3][2] = {
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,1},{0,1}},
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
};
enum BLOCK_TYPE {
	DOWN_LEFT, DOWN_RIGHT, UP_LEFT, UP_RIGHT
};
const char TYPE_NUM = 4;
const int UNDEFINED = -1;

using namespace std;

bool set(int r, int c, int H, int W, int type, char map[20][20], int weight) {
	bool status = true;
	for (int block = 0; block < 3; ++block) {
		int columnBlock = c + BLOCK_SHAPE[type][block][0];
		int rowBlock = r + BLOCK_SHAPE[type][block][1];
		if (rowBlock < 0 || rowBlock >= H || columnBlock < 0 || columnBlock >= W)
			status = false;
		if ((map[rowBlock][columnBlock] += weight) > 1)
			status = false;
	}
	return status;
}
int solve(int H, int W, char map[20][20]) {
	int nowRow = UNDEFINED;
	int nowCol = UNDEFINED;
	for (int row = 0; row < H && nowRow == UNDEFINED; ++row) {
		for (int col = 0; col < W; ++col) {
			if (!map[row][col]) {
				nowRow = row;
				nowCol = col;
				break;
			}
		}
	}
	if (nowRow == UNDEFINED)
		return 1;

	int num = 0;
	for (int nextType = DOWN_LEFT; nextType < TYPE_NUM; ++nextType) {
		if (set(nowRow, nowCol, H, W, nextType, map, 1)) {
			num += solve(H, W, map);
		}
		set(nowRow, nowCol, H, W, nextType, map, -1);
	}
	return num;
}
int main() {
	int C;
	scanf("%d", &C);
	while (C--) {
		int H, W;
		scanf("%d %d", &H, &W);
		char map[20][20] = { 0, };
		for (int r = 0; r < H; ++r) {
			scanf("%s", map[r]);
		}
		int num = 0;
		for (int r = 0; r < H; ++r) {
			for (int c = 0; c < W; ++c) {
				if (map[r][c] == BLACK)
					map[r][c] = 1;
				else
					map[r][c] = 0;
			}
		}
		num = solve(H, W, map);
		printf("%d\n", num);
	}
}