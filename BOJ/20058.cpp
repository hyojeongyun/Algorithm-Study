#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, q;
int icesize;
int ice[66][66];
int visit[66][66];
vector<int> magic;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void rotate(int i, int j, int L) {
	int num = L / 2;

	for (int s = 0; s < num; s++) {
		vector<int> temp1;
		vector<int> temp2;
		vector<int> temp3;
		vector<int> temp4;
		int r1 = i + s;
		int c1 = j + s;
		int r2 = i + L - 1 - s;
		int c2 = j + L - 1 - s;

		for (int c = c1; c < c2; c++) {
			temp1.push_back(ice[r1][c]);
		}
		for (int r = r1; r < r2; r++) {
			temp2.push_back(ice[r][c2]);
		}
		for (int c = c2; c > c1; c--) {
			temp3.push_back(ice[r2][c]);
		}
		for (int r = r2; r > r1; r--) {
			temp4.push_back(ice[r][c1]);
		}
		int cnt = 0;
		for (int c = c1; c < c2; c++) {
			ice[r1][c] = temp4[cnt];
			cnt++;
		}
		cnt = 0;
		for (int r = r1; r < r2; r++) {
			ice[r][c2] = temp1[cnt];
			cnt++;
		}
		cnt = 0;
		for (int c = c2; c > c1; c--) {
			ice[r2][c] = temp2[cnt];
			cnt++;
		}
		cnt = 0;
		for (int r = r2; r > r1; r--) {
			ice[r][c1] = temp3[cnt];
			cnt++;
		}
	}
}

void melt() {
	vector < pair<int, int>> v;
	for (int i = 0; i < icesize; i++) {
		for (int j = 0; j < icesize; j++) {
			if (ice[i][j] == 0) continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dx[k];
				int nc = j + dy[k];

				if (nr < 0 || nr >= icesize || nc < 0 || nc >= icesize) continue;

				if (ice[nr][nc] != 0)cnt++;
			}
			if (cnt < 3) v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		ice[v[i].first][v[i].second]--;
	}
}

int bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visit[i][j] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nr = r + dx[k];
			int nc = c + dy[k];

			if (nr >= 0 && nr < icesize && nc >= 0 && nc < icesize) {
				if (visit[nr][nc] == 0 && ice[nr][nc]!=0) {
					visit[nr][nc] = 1;
					q.push({ nr, nc });
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	icesize = pow(2, n);

	for (int i = 0; i < icesize; i++) {
		for (int j = 0; j < icesize; j++) {
			cin >> ice[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		magic.push_back(a);
	}

	for (int t = 0; t < q; t++) {
		//파이어스톰 1번 시전
		int L = pow(2, magic[t]);

		//회전
		for (int i = 0; i < icesize; i+=L) {
			for (int j = 0; j < icesize; j += L) {
				rotate(i, j, L);
			}
		}

		//얼음 양 감소
		melt();

	}

	//남아있는 얼음의 합
	int result1 = 0;
	for (int i = 0; i < icesize; i++) {
		for (int j = 0; j < icesize; j++) {
			result1 += ice[i][j];
		}
	}


	//남아있는 얼음 중 가장 큰 덩어리 칸 개수
	int result2 = 0;

	for (int i = 0; i < icesize; i++) {
		for (int j = 0; j < icesize; j++) {
			if (ice[i][j] != 0 && visit[i][j] == 0) {
				int re = bfs(i, j);
				result2 = max(result2, re);
			}
		}
	}

	cout << result1 << "\n";
	cout << result2 << "\n";
	return 0;
}