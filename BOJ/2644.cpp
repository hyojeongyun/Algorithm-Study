#include <iostream>
using namespace std;
int n,m;
int start, finish;
int map[101][101];
int visit[101];
int result = -1;

void dfs(int n, int cnt) {
	visit[n] = 1;

	if (n == finish) {
		result = cnt;
	}

	for (int i = 1; i < 100; i++) {
		if (i != n && map[n][i] == 1 && visit[i] == 0) {
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> start >> finish;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(start, 0);

	cout << result << '\n';

	return 0;
}