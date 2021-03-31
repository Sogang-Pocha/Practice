#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 1010;

int tc, cnt;
int n;
string str1, str2;

int dp[mxn][mxn];

void trace(int n, int m) {

	if (dp[n][m] == 0) return;

	if ((dp[n][m] != dp[n - 1][m] && dp[n][m] != dp[n][m - 1]) && dp[n][m] == dp[n - 1][m - 1] + 1) {
		trace(n - 1, m - 1);
		cout << str1[n - 1];
	}
	else {
		if (dp[n - 1][m] > dp[n][m - 1]) {
			trace(n - 1, m);
		}
		else {
			trace(n, m - 1);
		}
	}
}

int main() {
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

		}
	}

	cout << dp[str1.size()][str2.size()] << '\n';
	trace(str1.size(), str2.size());

	return 0;
}