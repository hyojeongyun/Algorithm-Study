#include <iostream>
#include <algorithm>
using namespace std;
int n, m, h;
int ladder[31][11];
int findCnt = 5;

bool play() {
	bool result = true;

	for (int i = 1; i <= n; i++) {
		int now = i;

		for (int j = 1; j <= h; j++) {
			if (ladder[j][now] == 1) {
				now += 1;
			}
			else if (now>=1 && ladder[j][now - 1] == 1) {
				now -= 1;
			}
		}

		if (now != i) {
			result = false;
			break;
		}
	}

	return result;
}

void addLine(int idx, int cnt) {
	if (cnt > 3) {
		return;
	}

	if (play() == true) {
		findCnt = min(findCnt, cnt);
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j] == 1 || ladder[i][j - 1] == 1 || ladder[i][j + 1] == 1) {
				continue;
			}

			ladder[i][j] = 1;
			addLine(i, cnt + 1);
			ladder[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	addLine(1, 0);

	if (findCnt > 3) {
		cout << -1 << '\n';
	}
	else {
		cout << findCnt << '\n';
	}

	return 0;
}