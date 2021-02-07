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
const int mxn = 111;

int tc, cnt;
int n;

int dp[mxn][mxn][mxn];



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i][5] = 1;

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < 10; k++) {
			if (k != 9) {
				dp[i][k][3] += dp[i - 1][k + 1][4] % MOD;
				dp[i][k][4] += (dp[i - 1][k + 1][5] + dp[i - 1][k + 1][6] + dp[i - 1][k + 1][7]) % MOD;
			}
			if (k != 0) {
				dp[i][k][7] += dp[i - 1][k - 1][6] % MOD;
				dp[i][k][6] += (dp[i - 1][k - 1][5] + dp[i - 1][k - 1][4] + dp[i - 1][k - 1][3]) % MOD;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++) {
		for (int k = 3; k <= 7; k++) {
			ans = (ans + dp[n][i][k]) % MOD;
		}
	}
	ans = (ans + MOD) % MOD;
	cout << ans;

	return 0;
}
