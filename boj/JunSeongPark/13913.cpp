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
const int mxn = 101010;

int tc, cnt;
int n, k;
int visit[mxn];
int pre[mxn];
vector<int> path;

int solve(int start, int finish) {
	queue<pii> q;
	q.push({ start, mxn - 1 });

	while (!q.empty()) {
		int here = q.front().first;
		int prev = q.front().second;
		q.pop();

		if (here < 0 || here > 100000) continue;
		if (visit[here]) continue;

		visit[here] = visit[prev] + 1;
		pre[here] = prev;

		if (here == finish) return visit[here] - 1;

		q.push({ here - 1, here });
		q.push({ here + 1, here });
		q.push({ 2 * here, here });
	}

	return -1;
}

void trace(int start, int finish) {
	for (int here = finish; here != mxn - 1; here = pre[here]) {
		path.push_back(here);
	}

	reverse(all(path));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	cout << solve(n, k) << '\n';

	trace(n, k);
	
	for (auto x : path)
		cout << x << ' ';

	return 0;
}
