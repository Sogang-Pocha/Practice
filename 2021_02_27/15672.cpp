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
const int mxn = 55;

// an : 그룹 A 크기, bn : 그룹 B 크기
int an, bn;
int A[mxn], B[mxn];
vector<int> adj[mxn];
bool visit[mxn];

bool dfs(int cur) {
	visit[cur] = true;

	for (auto next : adj[cur]) {
		if (B[next] == -1 || (!visit[B[next]] && dfs(B[next]))) {
			A[cur] = next;
			B[next] = cur;
			return true;
		}
	}
	return false;
}

int bmatch() {
	fill(A, A + an, -1);
	fill(B, B + bn, -1);
	int ret = 0;
	for (int i = 0; i < an; i++) {
		fill(visit, visit + bn, 0);

		if (dfs(i))
			ret++;
	}
	return ret;
}

pii a[mxn], b[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> an;
	bn = an;
	for (int i = 0; i < an; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < bn; i++)
		cin >> b[i].first >> b[i].second;

	int trace[mxn];
	int ans = -1, idx = -1;
	int n = an;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < n; l++) {
			for (int t = 0; t < n; t++) adj[t].clear();

			int STR = i, INT = l;
			int status = 0; // 0 : 기본 1 : 힘 2 : 지능
			for (int j = 0; j < n; j++) {
				if (j == STR) status = 1;
				if (j == INT) status = 2;
				if (status == 0) {
					for (int k = 0; k < n; k++) {
						if (b[k].first + b[k].second > a[j].first + a[j].second) {
							adj[k].push_back(j);
						}
					}
				}
				else if (status == 1) {
					for (int k = 0; k < n; k++) {
						if (b[k].first > a[j].first)
							adj[k].push_back(j);
					}
				}
				else {
					for (int k = 0; k < n; k++) {
						if (b[k].second > a[j].second)
							adj[k].push_back(j);
					}
				}
			}
			int cur = bmatch();
			if (ans < cur) {
				ans = cur;
				idx = i;
				for (int t = 0; t < n; t++) {
					trace[t] = B[t];
				}
			}
		}
	}

	cout << idx + 1 << '\n';
	bool check[mxn] = {};
	for (int i = 0; i < n; i++) {
		if (trace[i] == -1) continue;
		check[trace[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		if (trace[i] != -1) 
			cout << trace[i] + 1 << ' ';
		else {
			for (int j = 0; j < n; j++) {
				if (!check[j]) {
					cout << j + 1 << ' ';
					check[j] = true;
					break;
				}
			}
		}
	}

	return 0;
}
