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
int n;

priority_queue<int> M;
priority_queue<int, vector<int>, greater<int>> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (M.empty()) M.push(num);
		else if (m.empty()) {
			if (M.top() <= num) m.push(num);
			else {
				m.push(M.top());
				M.pop();
				M.push(num);
			}
		}
		else if (M.top() <= num) m.push(num);
		else M.push(num);

		if ((M.size() == m.size()) || (M.size() == m.size() + 1)) {

		}
		else if (M.size() > m.size()) {
			m.push(M.top());
			M.pop();
		}
		else {
			M.push(m.top());
			m.pop();
		}

		cout << M.top() << '\n';
	}


	return 0;
}
