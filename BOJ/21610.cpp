#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[52][52];
vector<pair<int, int>> cloud;

vector<pair<int, int>> nextmove;

int dirr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dirc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };

int daer[4] = {-1, -1, 1, 1};
int daec[4] = {-1, 1, -1, 1};

int cloudmap[52][52];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		nextmove.push_back({ a, b });
	}

	//최초 구름
	cloud.push_back({ n, 1 });
	cloud.push_back({ n, 2 });
	cloud.push_back({ n - 1, 1 });
	cloud.push_back({ n - 1, 2 });



	for (int i = 0; i < m; i++) {
		vector<pair<int, int>> newcloud;

		int d = nextmove[i].first;
		int s = nextmove[i].second;

		//구름이동
		for (int j = 0; j < cloud.size(); j++) {
			int r = cloud[j].first;
			int c = cloud[j].second;


			int nextr, nextc;
			if (dirr[d] != 0) {
				nextr = dirr[d] * s + r;
				while (nextr <= 0) {
					nextr += n;
				}
				while (nextr > n) {
					nextr -= n;
				}
			}
			else {
				nextr = r;
			}
			

			if (dirc[d] != 0) {
				nextc = dirc[d] * s + c;
				while (nextc <= 0) {
					nextc += n;
				}
				while (nextc > n) {
					nextc -= n;
				}
			}
			else {
				nextc = c;
			}
			

			map[nextr][nextc]++;
			newcloud.push_back({ nextr, nextc });

		}

		cloud.clear();


		//물복사버그마법
		for (int j = 0; j < newcloud.size(); j++) {
			int r = newcloud[j].first;
			int c = newcloud[j].second;

			for (int k = 0; k < 4; k++) {
				int nextr = daer[k] + r;
				int nextc = daec[k] + c;

				if (nextr > 0 && nextr <= n && nextc > 0 && nextc <= n) {

					if (map[nextr][nextc] > 0) {
						map[r][c]++;
					}
				}
			}
		}
		for (int p = 1; p <= n; p++) {
			for (int q = 1; q <= n; q++) {
				cloudmap[p][q] = 0;
			}
		}

		//다시 구름 생김
		for (int j = 0; j < newcloud.size(); j++) {
			int ncfirst = newcloud[j].first;
			int ncsecond = newcloud[j].second;
			cloudmap[ncfirst][ncsecond] = 1;
		}

		
		for (int p = 1; p <= n; p++) {
			for (int q = 1; q <= n; q++) {
				if (map[p][q] >= 2 && cloudmap[p][q] == 0) {
					cloud.push_back({ p, q });
					map[p][q] -= 2;
				}
			}
		}

	}

	int count = 0;
	for (int p = 1; p <= n; p++) {
		for (int q = 1; q <= n; q++) {
			count += map[p][q];
		}
	}
	cout << count << '\n';

	return 0;
}