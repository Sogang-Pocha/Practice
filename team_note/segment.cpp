class Seg {
public:
	int leaf = 1;
	vector<int> tree;

	int init(const vector<int >& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = INF;
		}

		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node * 2);
		int rightMin = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftMin, rightMin);
	}

	int init(const vector<int>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		return init(arr, 0, leaf - 1, 1);
	}

	int update(int idx, int newVal, int node, int nodeLeft, int nodeRight) {
		if (idx < nodeLeft || nodeRight < idx)
			return tree[node];

		if (nodeLeft == nodeRight)
			return tree[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;

		return tree[node] = func(update(idx, newVal, node * 2, nodeLeft, mid),
			update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
	}

	int update(int idx, int newVal) {
		return update(idx - 1, newVal, 1, 0, leaf - 1);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left)
			return INF;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return func(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	int func(int a, int b) {
		return min(a, b);
	}
};