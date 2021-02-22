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
int n, m;

struct MergesortTree {
	vector<int> seg[mxn * 4 + 50];

	void init(int l, int r, int node, vector<int>& arr) {
		if (l == r) {
			seg[node].push_back(arr[l]);
			return;
		}

		int mid = (l + r) / 2;

		init(l, mid, node * 2, arr); init(mid + 1, r, node * 2 + 1, arr);

		auto &left = seg[node * 2], &right = seg[node * 2 + 1];

		merge(all(left), all(right), back_inserter(seg[node]));
	}

	//[l, r]
	int query(int val, int l, int r, int node = 1, int nodeLeft = 0, int nodeRight = n - 1) {
		if (r < nodeLeft || nodeRight < l) return 0;

		if (l <= nodeLeft && nodeRight <= r)
			return seg[node].end() - upper_bound(all(seg[node]), val);

		int mid = (nodeLeft + nodeRight) / 2;
		return query(val, l, r, node * 2, nodeLeft, mid) + query(val, l, r, node * 2 + 1, mid + 1, nodeRight);
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	return 0;
}
