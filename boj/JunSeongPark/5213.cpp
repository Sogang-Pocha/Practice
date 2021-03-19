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

int arr[mxn][mxn];
int id[mxn][mxn];
int pre[mxn * mxn];
int visit[mxn * mxn];
int num;
vector<int> adj[mxn * mxn];

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (auto there : adj[here]) {
			if (visit[there]) continue;

			q.push(there);
			pre[there] = here;
			visit[there] = visit[here] + 1;
		}
	}
}

void trace() {
	vector<int> ans;
	int last = mxn * mxn - 1;
	while (last--) {
		if (pre[last] == 0) continue;
		for (int here = last; pre[here] != 0; here = pre[here])
			ans.push_back(here);
		ans.push_back(1);
		break;
	}

	if (n == 1)
		ans.push_back(1);

	cout << ans.size() << '\n';
	reverse(all(ans));
	for (auto x : ans)
		cout << x << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (int y = 0; y < n; y++) {
		int l = 0, r = 2 * n - 1;
		if (y % 2) {
			l++; r--;
		}

		for (int x = l; x < r; x += 2) {
			cin >> arr[y][x] >> arr[y][x + 1];
			num++;
			id[y][x] = id[y][x + 1] = num;
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 2 * n; x++) {
			if (id[y][x] == 0) continue;

			for (int i = 0; i < 4; i++) {
				int ny = y + dr[i];
				int nx = x + dc[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= 2 * n) continue;
				if (id[ny][nx] == 0) continue;
				if (id[y][x] == id[ny][nx]) continue;
				if (arr[y][x] != arr[ny][nx]) continue;

				adj[id[y][x]].push_back(id[ny][nx]);
			}
		}
	}

	bfs();
	trace();


	return 0;
}
