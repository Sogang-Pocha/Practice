#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
using namespace std;

#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1e9 + 7, INF = 987654321;
const ll LINF = 987654321987654321;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

const int mxn = 100001;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, idx;
    string s, s1, s2;
    cin >> s;
    f(i, s.size()) {
        if (s[i] == ':') {
            idx = i; break;
        }
    }
    s1 = s.substr(0, idx);
    s2 = s.substr(idx+1);
    n = stoi(s1);
    m = stoi(s2);
    int gcd;
    for (int i = 1; i <= min(m, n); i++) {
        if (m % i == 0 && n % i == 0) {
            gcd = i;
        }
    }
    cout << n / gcd << ':' << m / gcd;
}