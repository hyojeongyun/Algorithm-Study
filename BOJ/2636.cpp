#include <iostream>
#include <queue>
using namespace std;
int visit[101][101];
int map[101][101];
int n, m;
int last;
int t;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
		}
	}

	queue<pair<int, int>> qu;
	qu.push({ 0,0 });
	visit[0][0] = 1;
	t++;
	int cnt = 0;

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == 0) {
				if (map[nx][ny] == 1) {
					cnt++;
					map[nx][ny] = 0;
				}
				else if(map[nx][ny] == 0){
					qu.push({ nx, ny });
				}
				visit[nx][ny] = 1;
			}

		}
	}
	
	if (cnt == 0) {
		return true;
	}
	else {
		last = cnt;
		return false;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		if (bfs()) {
			cout << t-1 << '\n';
			cout << last << '\n';
			break;
		}
	}

	return 0;
}