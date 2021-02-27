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
int n;
pii arr[mxn];
lint dp[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr + 1, arr + n + 1);
	lint l, r, h;
	fill(dp, dp + mxn, LINF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		l = arr[i].first;
		r = arr[i].first;
		h = abs(arr[i].second);
		for (int j = i - 1; j >= 0; j--) {
			lint cost = max(r - l, 2 * h);
			dp[i] = min(dp[i], dp[j] + cost);
			l = arr[j].first;
			h = max(h, (lint)abs(arr[j].second));
		}
	}

	cout << dp[n];


	return 0;
}
