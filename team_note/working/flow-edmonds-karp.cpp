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
	int from, to, capacity, flow;
	edge *reverse_edge;

	edge(int u, int v, int c) : from(u), to(v), capacity(c), flow(0) {}

	int residual() {
		return capacity - flow;
	}

	void add_flow(int new_flow) {
		flow += new_flow;
		reverse_edge->flow -= new_flow;
	}
};

struct flow {
	int V, E; // # nodes, # edges
	int source, sink;
	vector<edge*> adj[mxn];

	int total_flow = 0;

	void init(int v, int e, int start, int end, bool directed = true) {
		int from, to, cost;

		V = v; E = e;
		source = start;
		sink = end;
		for (int i = 0; i < e; i++) {
			cin >> from >> to >> cost;
			add_edge(from, to, cost, directed);
		}
	}

	void add_edge(int u, int v, int c, bool directed = true) {
		edge *e1 = new edge(u, v, c);
		edge *e2 = new edge(v, u, (directed) ? 0 : c);
		e1->reverse_edge = e2;
		e2->reverse_edge = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	bool find_augmenting_path(int *trace, edge **back_edge) {
		for (int i = 0; i < mxn; i++) {
			trace[i] = -1;
			back_edge[i] = NULL;
		}

		queue<int> q;
		q.push(source);
		while (!q.empty() && trace[sink] == -1) {
			int cur = q.front();
			q.pop();
			for (auto e : adj[cur]) {
				int nxt = e->to;
				if (trace[nxt] == -1 && e->residual() > 0) {
					trace[nxt] = cur;
					back_edge[nxt] = e;
					q.push(nxt);
				}
			}
		}
		if (trace[sink] == -1) return false;
		return true;
	}

	int find_max_flow() {
		int trace[mxn];
		edge* back_edge[mxn] = { 0, };
		while (find_augmenting_path(trace, back_edge)) {
			int new_flow = INF;
			for (int i = sink; i != source; i = trace[i]) {
				new_flow = min(new_flow, back_edge[i]->residual());
			}
			for (int i = sink; i != source; i = trace[i]) {
				back_edge[i]->add_flow(new_flow);
			}
			total_flow += new_flow;
		}
		return total_flow;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	return 0;
}
