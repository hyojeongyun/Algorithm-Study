#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int people[22][22];
bool check[22];
int dif = 1000000000;
int n;

void dfs(int cnt, int next) {
	if (cnt == n / 2) {
		int team1 = 0;
		int team2 = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i] == true && check[j] == true) {
					team1 += people[i][j];
				}
				else if (check[i] == false && check[j] == false) {
					team2 += people[i][j];
				}
			}
		}

		int temp = abs(team1 - team2);

		if (dif > temp)dif = temp;

		return;
	}

	for (int i = next; i <= n; i++) {
		check[i] = true;
		dfs(cnt + 1, i + 1);
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {;
		for (int j = 1; j <= n; j++) {
			cin >> people[i][j];
		}
	}

	dfs(0, 1);

	cout << dif << '\n';

	return 0;
}