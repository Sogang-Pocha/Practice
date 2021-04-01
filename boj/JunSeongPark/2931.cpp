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
const int mxn = 30;

int tc, cnt;
int r, c;
string str[mxn];
bool visit[mxn][mxn];
const char ch[] = { '|', '-', '+', '1', '2', '3', '4', 'M', 'Z' };
const bool color[9][4] = { {1,0,1,0}, {0,1,0,1}, {1,1,1,1}, {0,0,1,1}, {1,0,0,1}, {1,1,0,0},{0,1,1,0}, {1,1,1,1}, {1,1,1,1} };

bool check() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] != '.' && !visit[y][x])
				return false;
			if (str[y][x] == '.' && visit[y][x])
				return false;
		}
	}
	return true;
}

int idx(int y, int x) {
	for (int i = 0; i < 9; i++)
		if (str[y][x] == ch[i]) return i;
}

void flow(int a, int b) {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push({ a, b });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int id = idx(y, x);
		q.pop();

		if (visit[y][x]) continue;
		visit[y][x] = true;

		if (str[y][x] == 'M' || str[y][x] == 'Z') continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (color[id][i]) {
				if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
					memset(visit, 0, sizeof(visit));
					return;
				}
				if (str[ny][nx] == '.' || !color[idx(ny, nx)][(i + 2) % 4]) {
					memset(visit, 0, sizeof(visit));
					return;
				}
				else {
					q.push({ ny, nx });
				}
			}
		}
	}
}

void solve() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (str[y][x] != '.') continue;

			for (int i = 0; i < 7; i++) {
				str[y][x] = ch[i];
				flow(y, x);
				if (check()) {
					cout << y + 1 << ' ' << x + 1 << ' ' << ch[i];
					return;
				}
			}
			str[y][x] = '.';

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int y = 0; y < r; y++)
		cin >> str[y];

	solve();
	
	return 0;
}
