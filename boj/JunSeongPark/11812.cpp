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
lint n, k, q;

lint solve(lint x, lint y) {
	lint ret = 0;
	while (true) {
		if (x == y) break;
		if (x < y) swap(x, y);

		x = (x - 1) / k;
		ret++;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k >> q;
	
	lint a, b;
	while (q--) {
		cin >> a >> b;
		a--; b--;
		if (k == 1) cout << abs(a - b) << '\n';
		else cout << solve(a, b) << '\n';
	}


	return 0;
}
