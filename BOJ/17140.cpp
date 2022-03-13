#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int arr[101][101];
int cnt[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	int time = 0;
	int row = 3; //За
	int col = 3; //ї­

	int result = 0;

	while (1) {
		if (arr[r][c] == k) {
			result = time;
			break;
		}

		vector<int> s;
		
		if (row >= col) { //R
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>> st;
				for (int j = 1; j < 101; j++) cnt[j] = 0;

				for (int j = 1; j <= col; j++) {
					cnt[arr[i][j]]++;
				}

				for (int j = 1; j < 101; j++) {
					if (cnt[j] != 0) st.push_back({ cnt[j], j });
				}
				sort(st.begin(), st.end());

				for (int j = 1; j <= col; j++) {
					arr[i][j] = 0;
				}

				int idx = 1;
				for (int j = 0; j < st.size(); j++) {
					arr[i][idx] = st[j].second;
					idx++;
					arr[i][idx] = st[j].first;
					idx++;
				}
				idx--;
				s.push_back(idx);
			}

			sort(s.begin(), s.end());
			col = s.back();
		}
		else  { //C
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>> st;
				for (int j = 1; j < 101; j++) cnt[j] = 0;

				for (int j = 1; j <= row; j++) {
					cnt[arr[j][i]]++;
				}

				for (int j = 1; j < 101; j++) {
					if (cnt[j] != 0) st.push_back({ cnt[j], j });
				}
				sort(st.begin(), st.end());

				for (int j = 1; j <= row; j++) {
					arr[j][i] = 0;
				}

				int idx = 1;
				for (int j = 0; j < st.size(); j++) {
					arr[idx][i] = st[j].second;
					idx++;
					arr[idx][i] = st[j].first;
					idx++;
				}
				idx--;
				s.push_back(idx);
			}

			sort(s.begin(), s.end());
			row = s.back();
		}

		time++;
		if (time > 100) {
			result = -1;
			break;
		}
	}

	cout << result << '\n';
	return 0;
}