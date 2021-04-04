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
const int mxn = 1515;

int tc, cnt;
int n;
int r, c;

char _map[mxn][mxn];
int turn[mxn][mxn];
int visit[mxn][mxn];
pii S, T;
queue<pii> q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx]) continue;

			turn[ny][nx] = turn[y][x] + 1;
			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}

bool solve(int day) {
	q = queue<pii>();
	memset(visit, false, sizeof(visit));
	q.push(S);
	q.push(T);
	visit[S.first][S.second] = 1;
	visit[T.first][T.second] = 2;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];
			
	
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (turn[ny][nx] > day) continue;
			if (visit[ny][nx] && (visit[ny][nx] != visit[y][x])) return true;
			if (visit[ny][nx]) continue;

			q.push({ ny,nx });
			visit[ny][nx] = visit[y][x];
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	
	S.first = T.first = -1;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> _map[y][x];

			if (_map[y][x] == '.') {
				q.push({ y,x });
				visit[y][x] = true;
			}
			else if (_map[y][x] == 'L') {
				q.push({ y,x });
				visit[y][x] = true;
				_map[y][x] = '.';
				if (S.first == -1) S = { y,x };
				else T = { y, x };
			}
		}
	}

	bfs();

	int l = 0, r = mxn;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (solve(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}

	cout << ans;

	return 0;
}
