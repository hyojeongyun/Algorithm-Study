#include <iostream>
#include <algorithm>
using namespace std;
int n, l;
int h[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	sort(h, h + n);

	for (int i = 0; i < n; i++) {
		if (l >= h[i]) {
			l++;
		}
		else {
			break;
		}
	}

	cout << l << '\n';

	return 0;
}