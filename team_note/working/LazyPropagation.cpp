class LazyPropagation {
public:
	int leaf = 1;
	int N;
	vector<lint> tree;
	vector<lint> lazy;


	lint init(const vector<lint>& arr, int left, int right, int node) {
		if (left == right) {
			if (left < arr.size())
				return tree[node] = arr[left];
			else
				return tree[node] = 0;
		}

		int mid = (left + right) / 2;
		lint leftSum = init(arr, left, mid, node * 2);
		lint rightSum = init(arr, mid + 1, right, node * 2 + 1);
		return tree[node] = func(leftSum, rightSum);
	}

	lint init(const vector<lint>& arr) {
		for (leaf = 1; arr.size() > leaf; leaf <<= 1);
		tree.resize(leaf << 1);
		lazy.resize(leaf << 1);
		N = arr.size();
		return init(arr, 0, leaf - 1, 1);
	}

	void update(int left, int right, lint addVal, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] += (lint)(nodeRight - nodeLeft + 1) * lazy[node];
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return;

		if (left <= nodeLeft && nodeRight <= right) {
			tree[node] += (nodeRight - nodeLeft + 1) * addVal;
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] += addVal;
				lazy[node * 2] += addVal;
			}
			return;
		}

		int mid = (nodeLeft + nodeRight) / 2;

		update(left, right, addVal, node * 2, nodeLeft, mid);
		update(left, right, addVal, node * 2 + 1, mid + 1, nodeRight);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	void update(int left, int right, lint addVal) {
		update(left - 1, right - 1, addVal, 1, 0, leaf - 1);
	}

	lint query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (lazy[node] != 0) {
			tree[node] += (lint)(nodeRight - nodeLeft + 1) * lazy[node];
			if (nodeLeft != nodeRight) {
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		if (right < nodeLeft || nodeRight < left)
			return 0;

		if (left <= nodeLeft && nodeRight <= right)
			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return func(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	lint query(int left, int right) {
		return query(left - 1, right - 1, 1, 0, leaf - 1);
	}

	lint func(lint a, lint b) {
		return a + b;
	}
};