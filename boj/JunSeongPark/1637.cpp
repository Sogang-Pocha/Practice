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
const int mxn = 20202;

int tc, cnt;
int n;
lint a[mxn], b[mxn], c[mxn];

lint solve(lint x) {
	lint ret = 0;
	for (int i = 0; i < n; i++) {
		if (x < a[i]) continue;
		ret += (min(x, c[i]) - a[i]) / b[i] + 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> c[i] >> b[i];

	lint lo = 1, hi = LINF;

	while (lo <= hi) {
		lint mid = (lo + hi) / 2LL;

		if (solve(mid) & 1)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	if (lo > LINF) cout << "NOTHING";
	else cout << lo << ' ' << solve(lo) - solve(lo - 1);

	return 0;
}
