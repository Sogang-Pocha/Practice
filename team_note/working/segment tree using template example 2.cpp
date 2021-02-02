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

template <typename T>
class Seg {
public:
	int leaf = 1;
	vector<T> tree;

	T init(const vector<T>& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = T();
		}

		int mid = (left + right) / 2;
		T leftMin = init(arr, left, mid, node * 2);
		T rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
	}

	T init(const vector<T>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}

	T update(int idx, T newVal, int node, int nodeLeft, int nodeRight) {
		if (idx < nodeLeft || nodeRight < idx)
			return tree[node];

		if (nodeLeft == nodeRight)
			return tree[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = func(update(idx, newVal, node * 2, nodeLeft, mid),
			update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
	}

	T update(int idx, int newVal) {
		return update(idx - 1, newVal, 1, 0, leaf - 1);
	}

	T query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return T();

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return func(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	T query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	T func(T a, T b) {
		return a + b;
	}
};

struct node {
	int num;

	node() {num = 2*INF;}
	node(int num) : num(num) {}

	node operator+(const node& rhs) const {
		return num < rhs.num ? node(num) : node(rhs.num);
	}
};

Seg<node> seg;
vector<node> arr;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].num;
	}

	seg.init(arr);

	int a, b;
	while (m--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << seg.query(a, b).num << '\n';
	}

	return 0;
}
