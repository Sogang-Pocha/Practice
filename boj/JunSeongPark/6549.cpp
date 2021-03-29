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
const int mxn = 101010;

int tc, cnt;
lint n;
lint h[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> h[i];

		h[n] = 0;
		stack<lint> st;
		st.push(0);
		lint ans = 0;

		for (int i = 0; i <= n; i++) {
			while (!st.empty() && h[st.top()] >= h[i]) {
				lint j = st.top();
				st.pop();
				lint w = -1;

				if (st.empty())
					w = i;
				else
					w = (i - st.top() - 1);
				ans = max(ans, h[j] * w);
			}
			st.push(i);
		}

		cout << ans << '\n';
	}


	return 0;
}
