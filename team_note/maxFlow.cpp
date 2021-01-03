const int mxn = 402;

vector<int> adj[mxn];
int c[mxn][mxn], f[mxn][mxn], visit[mxn];
int ans;


void maxFlow(int start, int end) {
	while (true) {
		fill(visit, visit + mxn, -1);
		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int next : adj[now]) {

				if (visit[next] == -1 && c[now][next] - f[now][next] > 0) {
					q.push(next);
					visit[next] = now;
					if (next == end)
						break;
				}
			}
		}

		if (visit[end] == -1)
			break;

		int flow = INF;
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}

		ans += flow;
	}
}