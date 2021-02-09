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

int tc, cnt;
int n, m, k;

struct edge {
	int from, to, cost;

	edge(int u, int v, int c) : from(u), to(v), cost(c) {}

	bool operator<(const edge& rhs) const {
		return cost > rhs.cost;
	}

	bool operator()(const edge& rhs) const {
		return cost > rhs.cost;
	}
};

struct MST {
	int V;
	vector<edge*> adj[mxn];
	int par[mxn];
	priority_queue<edge*> pq;
	vector<edge*> mst;

	MST() {
		memset(par, -1, sizeof(par));
	}

	void add_edge(int u, int v, int c) {
		edge *e1 = new edge(u, v, c);
		edge *e2 = new edge(v, u, c);
		adj[u].push_back(e1);
		adj[v].push_back(e2);
		pq.push(e1);
	}

	int find(int x) {
		if (par[x] == -1) return x;
		return par[x] = find(par[x]);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return false;

		par[y] = x;
		return true;
	}

	int find_mst() {
		int ret = 0;

		while (!pq.empty()) {
			edge *e = pq.top();
			pq.pop();

			if (merge(e->from, e->to)) {
				ret += e->cost;
				mst.push_back(e);
			}
		}
		return ret;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	return 0;
}
