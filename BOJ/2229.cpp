#include <iostream>
#include <algorithm>
using namespace std;
int n;
int stu[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stu[i];
	}

	for (int i = 1; i <= n; i++) {
		int high = -1;
		int low = 10001;
		int d = 0;

		for (int j = i; j > 0; j--) {
			high = max(high, stu[j]);
			low = min(low, stu[j]);
			d = max(d, dp[j-1] + high - low);
		}

		dp[i] = d;
	}

	cout << dp[n] << '\n';

	return 0;
}