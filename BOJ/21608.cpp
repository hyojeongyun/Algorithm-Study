#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int room[21][21];
int n;
int emp[21][21];
int like[401][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 || i == n) {
				if (j == 1 || j == n) {
					emp[i][j] = 2;
				}
				else {
					emp[i][j] = 3;
				}
			}
			else {
				if (j == 1 || j == n) {
					emp[i][j] = 3;
				}
				else {
					emp[i][j] = 4;
				}
			}
		}
	}

	for (int i = 0; i < n * n; i++) {
		int student;
		cin >> student;
		cin>> like[student][0]>>like[student][1]>>like[student][2]>>like[student][3];

		vector < pair<int, pair<int, pair<int, int>>>> v;
		int likefriend[21][21];
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				likefriend[r][c] = 0;
			}
		}

		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				for (int k = 0; k < 4; k++) {
					if (room[r][c] == like[student][k]) {
						if (r - 1 >= 1) {
							likefriend[r - 1][c]++;
						}
						if (r + 1 <= n) {
							likefriend[r + 1][c]++;
						}
						if (c - 1 >= 1) {
							likefriend[r][c - 1]++;
						}
						if (c + 1 <= n) {
							likefriend[r][c + 1]++;
						}
						break;
					}
				}
			}
		}

		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				if (room[r][c] == 0) {
					v.push_back({ likefriend[r][c], {emp[r][c], {r*(-1), c*(-1)}} });
				}
			}
		}

		sort(v.begin(), v.end(), greater<>());

		int findr = v[0].second.second.first * (-1);
		int findc = v[0].second.second.second *(-1);
		room[findr][findc] = student;

		if (findr - 1 >= 1) {
			emp[findr - 1][findc]--;
		}
		if (findr + 1 <= n) {
			emp[findr + 1][findc]--;
		}
		if (findc - 1 >= 1) {
			emp[findr][findc - 1]--;
		}
		if (findc + 1 <= n) {
			emp[findr][findc + 1]--;
		}
	}
	int result = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int s = room[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				
				
				for (int p = 0; p < 4; p++) {
					if (room[nx][ny] == like[s][p]) {
						cnt++;
						break;
					}
				}
			}

			if (cnt == 1) result += 1;
			else if (cnt == 2) result += 10;
			else if (cnt == 3) result += 100;
			else if (cnt == 4) result += 1000;
		}
	}
	cout << result << '\n';

	return 0;
}