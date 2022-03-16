#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string>v;
int alphabet[27];

bool cmp(int a, int b) {
	if (a > b)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back({s, 0});
	}

	for (int i = 0; i < n; i++) {
		string s = v[i];

		int cnt = 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			alphabet[s[j] - 'A'] += cnt;
			cnt *= 10;
		}
	}

	sort(alphabet, alphabet+26, cmp);

	int result = 0;
	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)break;
		result += alphabet[i] * num;
		num--;
	}
	cout << result << '\n';


	return 0;
}