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
const int mxn = 10101;

int tc, cnt;
int n, m;
int tmp[mxn];
vector<int> arr;
int dp[mxn];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp[i];
		arr.push_back(tmp[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			arr.push_back(tmp[i] + tmp[j]);
		}
	}

	sort(all(arr));
	unique(all(arr));
	fill(dp, dp + mxn, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : arr) {
			if (i - x < 0) break;
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}

	if (dp[n] == INF) cout << -1;
	else cout << dp[n];

	return 0;
}
