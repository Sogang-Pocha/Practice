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
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 1010;

int tc, cnt;
int n;

int cost[mxn][3];
int dp[mxn][3][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	fill(dp[0][0], dp[0][0] + mxn * 3 * 3, INF);

	dp[0][0][0] = cost[0][0];
	dp[0][1][1] = cost[0][1];
	dp[0][2][2] = cost[0][2];

	for (int start = 0; start < 3; start++) {
		for (int i = 1; i < n; i++) {
			dp[i][start][0] = min(dp[i - 1][start][1], dp[i - 1][start][2]) + cost[i][0];
			dp[i][start][1] = min(dp[i - 1][start][0], dp[i - 1][start][2]) + cost[i][1];
			dp[i][start][2] = min(dp[i - 1][start][0], dp[i - 1][start][1]) + cost[i][2];
		}
	}

	int ans = INF;
	for (int start = 0; start < 3; start++) {
		for (int i = 0; i < 3; i++) {
			if (start == i) continue;
			ans = min(ans, dp[n - 1][start][i]);
		}
	}

	cout << ans;

	return 0;
}
