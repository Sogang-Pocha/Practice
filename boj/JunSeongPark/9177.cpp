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
const int mxn = 10000;

int tc, cnt;
int n;
string a, b, c;
int dp[202][202];

int solve(int idx1, int idx2) {
	int &ret = dp[idx1][idx2];

	if (ret != -1) return ret;
	if (idx1 == a.size() - 1 && idx2 == b.size() - 1) return ret = 1;

	ret = 0;
	if (c[idx1 + idx2] == a[idx1]) ret = max(ret, solve(idx1 + 1, idx2));
	if (c[idx1 + idx2] == b[idx2]) ret = max(ret, solve(idx1, idx2 + 1));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> a >> b >> c;
		a += '#';
		b += '#';
		memset(dp, -1, sizeof(dp));

		if (solve(0, 0) == 1)
			cout << "Data set " << i << ": yes\n";
		else
			cout << "Data set " << i << ": no\n";
	}


	return 0;
}
