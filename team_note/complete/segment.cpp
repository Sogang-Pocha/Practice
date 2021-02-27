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

class Seg {
public:
	int leaf = 1;
	vector<lint> tree;

	lint init(const vector<lint>& arr, lint left, lint right, lint node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = INF;
		}

		lint mid = (left + right) / 2;
		lint leftMin = init(arr, left, mid, node * 2);
		lint rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
	}

	lint init(const vector<lint>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}

	lint update(lint idx, lint newVal, lint node, lint nodeLeft, lint nodeRight) {
		if (idx < nodeLeft || nodeRight < idx)
			return tree[node];

		if (nodeLeft == nodeRight)
			return tree[node] = newVal;

		lint mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = func(update(idx, newVal, node * 2, nodeLeft, mid),
			update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
	}

	lint update(int idx, int newVal) {
		return update(idx - 1, newVal, 1, 0, leaf - 1);
	}

	lint query(lint left, lint right, lint node, lint nodeLeft, lint nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return INF;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return func(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	lint query(lint left, lint right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	lint func(lint a, lint b) {
		return min(a, b);
	}
};

int tc, cnt;
int n;

vector<lint> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);




	return 0;
}
