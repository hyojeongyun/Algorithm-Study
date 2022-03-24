#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct FISH {
	int x;
	int y;
	int dir;
	int live;
};

int map[17][17];
FISH fish[17];
int eat;
int dirx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int diry[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live == 0) continue;

		int x = fish[i].x;
		int y = fish[i].y;
		int d = fish[i].dir;

		int nx = x + dirx[d];
		int ny = y + diry[d];
		int nd = d;

		//갈 수 있을 때까지 방향 바꾸기
		while (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || map[nx][ny] == -1) {
			nd = (nd + 1) % 8;
			nx = x + dirx[nd];
			ny = y + diry[nd];
		}

		if (map[nx][ny] == 0) { //빈칸
			fish[i].x = nx;
			fish[i].y = ny;
			fish[i].dir = nd;
			map[x][y] = 0;
			map[nx][ny] = i;
		}
		else { //다른 물고기
			int temp = map[nx][ny];
			fish[i].x = nx;
			fish[i].y = ny;
			fish[i].dir = nd;
			fish[temp].x = x;
			fish[temp].y = y;
			map[x][y] = temp;
			map[nx][ny] = i;
		}

	}
}

void dfs(int x, int y, int dir, int cnt) {
	eat = max(cnt, eat);

	int copymap[16][16];
	FISH copyfish[17];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copymap[i][j] = map[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		copyfish[i] = fish[i];
	}


	moveFish();


	for (int i = 1; i <= 3; i++) {
		int nx = x + dirx[dir] * i;
		int ny = y + diry[dir] * i;

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;

		if (map[nx][ny] == 0) continue;

		int n = map[nx][ny];
		int d = fish[n].dir;

		map[x][y] = 0;
		map[nx][ny] = -1;
		fish[n].live = 0;

		dfs(nx, ny, d, cnt + n);

		map[x][y] = -1;
		map[nx][ny] = n;
		fish[n].live = 1;
	
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = copymap[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		fish[i] = copyfish[i];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;

			map[i][j] = a;
			fish[a] = { i, j, b - 1, 1 };
		}
	}

	int n = map[0][0];
	int d = fish[map[0][0]].dir;
	fish[map[0][0]].live = 0;
	map[0][0] = -1; // 상어가 있으면 -1

	dfs(0, 0, d, n);

	cout << eat << '\n';

	return 0;
}