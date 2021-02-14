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
const int mxn = 1050;

struct node {
	int a, b, c;

	bool operator!=(const node& rhs) const {
		return (a == rhs.a || b == rhs.b) && (c != rhs.c);
	}
};

node arr[mxn];
bool check[mxn];
int d[mxn];
int tc, cnt;
int n, m, k;
vector<int> adj[mxn];


bool dfs(int cur) {

	for (auto next : adj[cur]) {
		if (check[next]) continue;
		check[next] = true;
		
		if (d[next] == 0 || dfs(d[next])) {
			d[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= k; i++)
		cin >> arr[i].a >> arr[i].b >> arr[i].c;

	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			if (arr[i] != arr[j]) {
				if (arr[i].c == 0) adj[i].push_back(j);
				else adj[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i)) cnt++;
	}

	cout << cnt;


	return 0;
}
