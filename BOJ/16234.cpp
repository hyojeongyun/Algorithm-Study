#include <iostream>
#include <queue>
using namespace std;
int N, L, R;
int a[51][51];
int na[51][51];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int visit[51][51];
bool f = false;

void bfs(int r, int c, int cnt) {
	queue<pair<int, int>>qu;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr < N && nc >= 0 && nc < N && visit[nr][nc] == 0) {
			if (abs(a[r][c] - a[nr][nc]) >= L && abs(a[r][c] - a[nr][nc]) <= R) {
				f = true;
				qu.push({ r, c });
				visit[r][c] = cnt;
				break;
			}
		}

	}

	while (!qu.empty()) {
		int r = qu.front().first;
		int c = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < N && nc >= 0 && nc < N && visit[nr][nc] == 0) {
				if (abs(a[r][c] - a[nr][nc]) >= L && abs(a[r][c] - a[nr][nc]) <= R) {
					qu.push({ nr, nc });
					visit[nr][nc] = cnt;
				}
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	int day = 0;

	while (1) {
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j]==0) {
					bfs(i, j, cnt);
					if (f == false) continue;

					int people = 0;
					int country = 0;

					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							if (visit[r][c] == cnt) {
								people += a[r][c];
								country++;
							}
						}
					}

					int newpeople = people / country;

					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							if (visit[r][c] == cnt) {
								na[r][c] = newpeople;
							}
						}
					}

					cnt++;
					f = false;
				}
			}
		}

		bool find = false;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (na[r][c] != 0)find = true;
			}
		}
		if (find == false) {
			cout << day << '\n';
			break;
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (na[r][c] != 0) {
					a[r][c] = na[r][c];
				}
			}
		}

		day++;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				visit[r][c] = 0;
				na[r][c] = 0;
			}
		}

	}

	return 0;
}