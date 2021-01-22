#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

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
const double PI = 3.14159265359;
const int mxn = 10000;

int n;

int dp[2000][3];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	dp[1][1] = dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = (dp[i - 1][(j + 2) % 3] + dp[i - 1][(j + 1) % 3]) % MOD;
		}
	}

	//int ans = ((dp[n - 1][1] + dp[n - 1][4]) % MOD + dp[n - 1][7]) % MOD;

	cout << dp[n - 1][1];


	return 0;
}