#include <iostream>
#include <queue>
using namespace std;
int n, k;
int map[100001];
int visit[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int res = 0;

	queue<pair<int, int>> qu;
	visit[n] = 1;
	qu.push({ n, 0 });

	while (!qu.empty()) {
		int now = qu.front().first;
		int time = qu.front().second;
		qu.pop();
		
		if (now == k) {
			res = time;
			break;
		}
		
		if (now+1>=0 && now+1<=100000 && visit[now + 1] == 0) {

			visit[now + 1] = 1;
			qu.push({ now + 1 , time + 1 });
		}
		if (now - 1 >= 0 && now - 1 <= 100000 && visit[now - 1] == 0) {
			visit[now - 1] = 1;
			qu.push({ now - 1, time + 1 });
		}
		if (now * 2 >= 0 && now * 2 <= 100000 && visit[now * 2] == 0) {
			visit[now * 2] = 1;
			qu.push({ now * 2, time + 1 });
		}
	}

	cout << res << '\n';

	return 0;
}