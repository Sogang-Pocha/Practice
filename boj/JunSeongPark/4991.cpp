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

const int MOD = 1e9 + 7, INF = 5000;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 22;

int tc, cnt;
int n;
int r, c;
int visit[mxn][mxn];
int dist[mxn][mxn];
int dp[12][1 << 12];
char str[mxn][mxn];
vector<pii> v;
queue<pii> q;

void bfs(int idx) {
	memset(visit, 0, sizeof(visit));
	
	q.push(v[idx]);
	visit[v[idx].first][v[idx].second] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx]) continue;
			if (str[ny][nx] == 'x') continue;
			visit[ny][nx] = visit[y][x] + 1;

			if (str[ny][nx] == '*') {
				for (int k = 0; k < v.size(); k++) {
					if (ny == v[k].first && nx == v[k].second)
						dist[idx][k] = dist[k][idx] = visit[ny][nx] - 1;
				}
			}

			q.push({ ny,nx });

		}
	}
}

int solve(int visited, int cur) {
	if (visited == ((1 << v.size()) - 1)) 
		return 0;
	
	int &ret = dp[cur][visited];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < v.size(); i++) {
		if ((visited & (1 << i)) == 0) {
			if (dist[cur][i] == INF) continue;
			ret = min(ret, solve(visited | (1 << i), i) + dist[cur][i]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		cin >> c >> r;
		if (c == 0 && r == 0) break;
		int start;
		
		fill(dist[0], dist[0] + mxn * mxn, INF);
		memset(dp, -1, sizeof(dp));
		v.clear();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> str[i][j];
				if (str[i][j] == 'o') {
					start = v.size();
					str[i][j] = '*';
					v.push_back({i, j});
				}
				else if (str[i][j] == '*') {
					v.push_back({ i, j });
				}
			}
		}

		if (v.size() == 1) {
			cout << "0\n";
			continue;
		}
		
		for (int i = 0; i < v.size(); i++)
			bfs(i);

		int ans = solve(1 << start, start);

		if (ans >= INF)
			cout << "-1\n";
		else
			cout << ans << '\n';
		

	}

	return 0;
}
