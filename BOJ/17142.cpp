#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int map[51][51];
int visit[51][51];
int result = 5000;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> virus;
vector<pair<int, int>> temp;
int check[11];

void find() {

	queue<pair<int, int>> qu;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				visit[i][j] = 1;
			}
			else {
				visit[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		qu.push(temp[i]);
		visit[temp[i].first][temp[i].second] = 1;
	}

	while (!qu.empty()) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (visit[nx][ny] == 0) {
					qu.push( {nx, ny});
					
					visit[nx][ny] = visit[x][y] + 1;

				}
			}
		}
	}

	int time = 1;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] != 0) {
				if (map[i][j] == 0) {
					time = max(visit[i][j], time);

				}
			}
			else {
				ok = false;
			}
		}
	}
	if (ok) {
		result = min(result, time-1);
	}
}

void active(int j) {
	if (temp.size() == m) {

		find();

		return;
	}

	for (int i = j; i < virus.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			temp.push_back(virus[i]);
			active(i + 1);
			check[i] = 0;
			temp.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	active(0);

	if (result == 5000) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}