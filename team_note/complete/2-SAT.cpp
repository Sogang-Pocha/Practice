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
const int mxn = 2020;

// snum : SCC ����, sn[i] : i �� ���� SCC ��ȣ
int id, dfsn[mxn], snum, sn[mxn];
bool finished[mxn];
vector<int> adj[mxn];
stack<int> st;
vector<vector<int>> scc;

int make_scc(int cur) {
	dfsn[cur] = ++id;
	st.push(cur);

	int ret = dfsn[cur];
	for (auto next : adj[cur]) {

		//���� �湮���� ����
		if (dfsn[next] == 0) ret = min(ret, make_scc(next));

		//�湮�� ������ ���� scc�� �ȸ������
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

int oppo(int x) {
	return x % 2 ? x - 1 : x + 1;
}

void add_edge(int a, int b) {
	a = (a < 0 ? -(a + 1) * 2 : a * 2 - 1);
	b = (b < 0 ? -(b + 1) * 2 : b * 2 - 1);

	adj[oppo(a)].push_back(b);
	adj[oppo(b)].push_back(a);
}

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	return 0;
}