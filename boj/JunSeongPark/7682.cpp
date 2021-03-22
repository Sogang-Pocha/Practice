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
#include <unordered_set>
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

unordered_set<string> ans;
unordered_set<string> check;
string str = ".........";

bool finish() {
	if ((str[0] != '.') && (str[0] == str[1]) && (str[1] == str[2])) return true;
	if ((str[3] != '.') && (str[3] == str[4]) && (str[4] == str[5])) return true;
	if ((str[6] != '.') && (str[6] == str[7]) && (str[7] == str[8])) return true;
	if ((str[0] != '.') && (str[0] == str[3]) && (str[3] == str[6])) return true;
	if ((str[1] != '.') && (str[1] == str[4]) && (str[4] == str[7])) return true;
	if ((str[2] != '.') && (str[2] == str[5]) && (str[5] == str[8])) return true;
	if ((str[0] != '.') && (str[0] == str[4]) && (str[4] == str[8])) return true;
	if ((str[2] != '.') && (str[2] == str[4]) && (str[4] == str[6])) return true;

	for (int i = 0; i < 9; i++) 
		if (str[i] == '.') return false;
	
	return true;
}

void solve(int turn) {
	if (check.find(str) != check.end()) return;
	check.insert(str);

	if (finish()) {
		ans.insert(str);
		return;
	}
	char ch = (turn ? 'X' : 'O');
	for (int i = 0; i < 9; i++) {
		if (str[i] != '.') continue;
		str[i] = ch;
		solve(1 - turn);
		str[i] = '.';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solve(1);
	while (true) {
		getline(cin, str);
		if (str == "end") break;
		if (ans.find(str) == ans.end()) 
			cout << "invalid\n";
		else
			cout << "valid\n";
	}


	return 0;
}
