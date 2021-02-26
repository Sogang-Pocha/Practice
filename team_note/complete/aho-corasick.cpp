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
int n, m;
double ans = 0;

const int chd_mxn = 96;
const char start_word = 32;

struct trie {
	trie* chd[chd_mxn];
	trie* fail;

	bool output;

	trie() {
		fill(chd, chd + chd_mxn, nullptr);
		output = false;
	}

	~trie() {
		for (int i = 0; i < chd_mxn; i++)
			if (chd[i]) delete chd[i];
	}

	void insert(const string& key, int idx = 0) {

		if (idx == key.size())
			output = true;

		else {
			int next = key[idx] - start_word;

			if (!chd[next])
				chd[next] = new trie;

			chd[next]->insert(key, idx + 1);
		}
	}
};

void make_fail(trie *root) {
	queue<trie*> q;

	root->fail = root;
	q.push(root);

	trie *cur, *next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < chd_mxn; i++) {
			next = cur->chd[i];

			if (!next) continue;

			if (cur == root) {
				next->fail = root;
			}
			else {
				trie *dest = cur->fail;

				while (dest != root && !dest->chd[i])
					dest = dest->fail;

				if (dest->chd[i]) dest = dest->chd[i];
				next->fail = dest;
			}
			if (next->fail->output) next->output = true;

			q.push(next);
		}
	}
}

bool aho_corasick(string& str, trie* root) {
	trie* cur = root;
	for (auto x : str) {
		int next = x - start_word;

		while (cur != root && !cur->chd[next])
			cur = cur->fail;
		if (cur->chd[next])
			cur = cur->chd[next];
		if (cur->output) {
			return true;
			cur = root;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



	return 0;
}
