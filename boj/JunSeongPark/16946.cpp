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

int n, m;

string str[mxn];
bool visit[mxn][mxn];
int ans[mxn][mxn];
int id[mxn][mxn];
int idx;

void bfs(int y, int x) {
	int cnt = 1;
	queue<pii> q;
	q.push({ y, x });
	visit[y][x] = true;
	idx++;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dr[i];
			int nx = cur_x + dc[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visit[ny][nx] || str[ny][nx] == '1') continue;

			cnt++;
			visit[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	q.push({ y,x });
	visit[y][x] = false;
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dr[i];
			int nx = cur_x + dc[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!visit[ny][nx]) continue;

			ans[ny][nx] = cnt % 10;
			id[ny][nx] = idx;
			visit[ny][nx] = false;
			q.push({ ny, nx });
		}
	}
	id[y][x] = idx;
	ans[y][x] = cnt % 10;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (str[y][x] == '0' && id[y][x] == 0) bfs(y, x);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (str[y][x] == '0') cout << 0;
			else {
				int num = 1;
				set<int> tmp;
				for (int i = 0; i < 4; i++) {
					int ny = y + dr[i];
					int nx = x + dc[i];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (tmp.find(id[ny][nx]) != tmp.end()) continue;

					tmp.insert(id[ny][nx]);
					num += ans[ny][nx];
				}
				cout << num % 10;
			}
		}
		cout << '\n';
	}

	return 0;
}
