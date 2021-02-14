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
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 9;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 1010;

int tc, cnt;
int n;

lint dp[3][mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[1][i] = dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % LMOD;

		for (int j = 0; j < i - 1; j++) {
			dp[0][i] = (dp[0][i] + dp[2][j]) % LMOD;
			dp[2][i] = (dp[2][i] + dp[0][j]) % LMOD;
		}
	}

	cout << dp[2][n];

	return 0;
}
