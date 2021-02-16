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
const int mxn = 10101;

// snum : SCC 개수, sn[i] : i 가 속한 SCC 번호
int id, dfsn[mxn], snum, sn[mxn];
bool finished[mxn];
vector<int> adj[mxn];
stack<int> st;
vector<vector<int>> scc;

int v, e;

int make_scc(int cur) {
	dfsn[cur] = ++id;
	st.push(cur);

	int ret = dfsn[cur];
	for (auto next : adj[cur]) {

		//아직 방문하지 않음
		if (dfsn[next] == 0) ret = min(ret, make_scc(next));

		//방문은 했으나 아직 scc가 안만들어짐
		else if (!finished[next]) ret = min(ret, dfsn[next]);
	}

	if (ret == dfsn[cur]) {
		vector<int> tmp;

		while (true) {
			int t = st.top();
			st.pop();

			tmp.push_back(t);
			finished[t] = true;
			sn[t] = snum;
			if (t == cur) break;
		}

		scc.push_back(tmp);
		snum++;
	}

	return ret;
}




int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	return 0;
}
