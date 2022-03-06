#include <iostream>
using namespace std;
int map[101][101];
int check[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0; //지나갈 수 있는 길

	//가로줄
	for (int i = 0; i < n; i++) {
		int before = 1;
		bool can = true;

		for (int j = 1; j < n; j++) {
			//cout << "i: " << i << " j: " << j << '\n';
			
			if (map[i][j - 1] == map[i][j]) { //평지
				before++;
			}
			else if (map[i][j - 1] == map[i][j] + 1) {  //내리막
				int cnt = 1;
				for (int k = j+1; k < j + l; k++) {
					if (map[i][k - 1] == map[i][k]) cnt++;
				}

				if (cnt == l) {
					before = 0;
					j = j + l - 1;
				}
				else {
					can = false;
					break;
				}
			}
			else if (map[i][j - 1] == map[i][j] - 1) {  //오르막
				if (before >= l) {
					before = 1;
				}
				else {
					can = false;
					break;
				}
			}
			else { //높이 차이 2 이상
				can = false;
				break;
			}
		}

		if (can) result++;
		
	}

	//세로줄
	for (int j = 0; j < n; j++) {
		int before = 1;
		bool can = true;

		for (int i = 1; i < n; i++) {
			//cout << "i: " << i << " j: " << j << '\n';

			if (map[i-1][j] == map[i][j]) { //평지
				before++;
			}
			else if (map[i-1][j] == map[i][j] + 1) {  //내리막
				int cnt = 1;
				for (int k = i + 1; k < i + l; k++) {
					if (map[k-1][j] == map[k][j]) cnt++;
				}

				if (cnt == l) {
					before = 0;
					i = i + l - 1;
				}
				else {
					can = false;
					break;
				}
			}
			else if (map[i-1][j] == map[i][j] - 1) {  //오르막
				if (before >= l) {
					before = 1;
				}
				else {
					can = false;
					break;
				}
			}
			else { //높이 차이 2 이상
				can = false;
				break;
			}
		}
		if (can) result++;
	}

	cout << result << '\n';
	return 0;
}