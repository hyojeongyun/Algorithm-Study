#include <iostream>
#include <queue>
using namespace std;
int n, m;
int tree[1001][1001];
int visit[1001];
int dist;

void bfs(int start, int end) {
	queue<pair<int, int>> qu;
	qu.push({ start, 0 });
	visit[start] = 1;

	while (!qu.empty()) {
		int now = qu.front().first;
		int d = qu.front().second;
		qu.pop();

		if (now == end) {
			dist = d;
			break;
		}

		for (int i = 1; i <= n; i++) {
			if (tree[now][i] != 0 && visit[i] == 0) {
				visit[i] = 1;
				qu.push({ i, d + tree[now][i] });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b] = c;
		tree[b][a] = c;
	}
	for (int i = 0; i < m; i++) {

		for (int j = 0; j <= n; j++) {
			visit[j] = 0;
		}

		int start, end;
		cin >> start>>end;
		bfs(start, end);
		cout << dist << '\n';
	}

	return 0;
}