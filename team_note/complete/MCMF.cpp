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
const int mxn = 10000;

int tc, cnt;
int n, m, k;

struct edge {
	int from, to, capacity, cost, flow;
	edge *reverse_edge;

	edge(int u, int v, int cap, int c) : from(u), to(v), capacity(cap), cost(c), flow(0) {}

	int residual() {
		return capacity - flow;
	}

	void add_flow(int new_flow) {
		flow += new_flow;
		reverse_edge->flow -= new_flow;
	}
};

struct mcmf {
	int V, E; // # nodes, # edges
	int source, sink;
	vector<edge*> adj[mxn];

	int total_flow = 0;
	int total_cost = 0;

	void add_edge(int u, int v, int cap, int cost, bool directed = true) {
		edge *e1 = new edge(u, v, cap, cost);
		edge *e2 = new edge(v, u, (directed) ? 0 : cap, -cost);
		e1->reverse_edge = e2;
		e2->reverse_edge = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	pii get_mcmf(int S, int T) {
		source = S; sink = T;
		return get_mcmf();
	}

	pii get_mcmf() {
		total_cost = 0, total_flow = 0;
		while (true) {
			int parent[mxn], dist[mxn];
			edge *path[mxn];
			queue<int> Q;
			bool inQ[mxn] = {};

			memset(parent, -1, sizeof(parent));
			fill(dist, dist + mxn, INF);
			dist[source] = 0;
			Q.push(source);
			inQ[source] = true;

			while (!Q.empty()) {
				int cur = Q.front(); Q.pop();
				inQ[cur] = false;
				for (auto e : adj[cur]) {
					int next = e->to;
					if (e->residual() > 0 && dist[next] > dist[cur] + e->cost) {
						dist[next] = dist[cur] + e->cost;
						parent[next] = cur;
						path[next] = e;
						if (!inQ[next]) {
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if (parent[sink] == -1) break;

			int flow = INF;
			for (int i = sink; i != source; i = parent[i])
				flow = min(flow, path[i]->residual());
			for (int i = sink; i != source; i = parent[i]) {
				total_cost += flow * path[i]->cost;
				path[i]->add_flow(flow);
			}
			total_flow += flow;
		}

		return { total_cost, total_flow };
	}

};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



	return 0;
}
