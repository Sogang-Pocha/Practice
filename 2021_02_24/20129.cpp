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
int p1, p2, p3, p4;
string str;

int prio(char c) {
	if (c == '+') return p1;
	if (c == '-') return p2;
	if (c == '*') return p3;
	return p4;
}

lint cal(lint x, lint y, char op) {
	if (op == '+') 
		return x + y;
	if (op == '-')
		return x - y;
	if (op == '*')
		return x * y;
	
	if (x * y > 0) {
		return abs(x) / abs(y);
	}
	else {
		return -1LL * (abs(x) / abs(y));
	}
}

deque<char> op;
deque<char> op2;
deque<lint> num;
deque<lint> num2;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> p1 >> p2 >> p3 >> p4;
	cin >> str;

	int l, r;
	l = r = str.size() - 1;


	while (l >= 0) {
		if ('0' <= str[l] && str[l] <= '9') {
			l--;
			continue;
		}
		num.push_back(stol(str.substr(l + 1, r - l)));
		op.push_back(str[l]);
		r = --l;
	}
	if (r != -1)
		num.push_back(stol(str.substr(0, r + 1)));

	for (int p = 4; p >= 1; p--) {
		if (p % 2 == 0) {
			lint left = num[0], right = -1;
			num2 = deque<lint>();
			op2 = deque<char>();
			if (num.size() == 1) {
				cout << num[0];
				return 0;
			}
			for (int i = 1; i < num.size(); i++) {
				right = num[i];
				if (prio(op[i - 1]) == p) {
					left = cal(left, right, op[i - 1]);
					if (i == num.size() - 1) num2.push_back(left);
				}
				else {
					num2.push_back(left);
					left = right;
					op2.push_back(op[i - 1]);
					if (i == num.size() - 1) num2.push_back(right);
				}

			}
		}
		else {
			lint left = num2[0], right = -1;
			num = deque<lint>();
			op = deque<char>();
			if (num2.size() == 1) {
				cout << num2[0];
				return 0;
			}
			for (int i = 1; i < num2.size(); i++) {
				right = num2[i];
				if (prio(op2[i - 1]) == p) {
					left = cal(left, right, op2[i - 1]);
					if (i == num2.size() - 1) num.push_back(left);
				}
				else {
					num.push_back(left);
					left = right;
					op.push_back(op2[i - 1]);
					if (i == num2.size() - 1) num.push_back(right);
				}

			}
		}
	}

	cout << num[0];

	return 0;
}
