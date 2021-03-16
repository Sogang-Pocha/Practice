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
const int mxn = 101;

int tc, cnt;
int n, m, k;
int dp[mxn][mxn][mxn];
string str[mxn];
string s;

int solve(int y, int x, int idx) {
	int&ret = dp[y][x][idx];

	if (ret != -1) return ret;
	if (idx == s.size()) return ret = 1;

	ret = 0;
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i] * j;
			int nx = x + dc[i] * j;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (str[ny][nx] == s[idx]) 
				ret += solve(ny, nx, idx + 1);
			

		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> str[i];
	cin >> s;
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (str[y][x] == s[0]) {
				ans += solve(y, x, 1);
			}
		}
	}

	cout << ans;

	return 0;
}
