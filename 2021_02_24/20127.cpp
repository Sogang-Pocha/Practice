#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using ll = long long;

const int MOD = 1e9 + 7, INF = 987654321;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
const int mxn = 1000001;
vector<int> n(mxn), m(mxn);
int ans=INF, k;

int func(vector<int>&v) {
    int cut = -1;
    f(i, k-1) {
        if (v[i] > v[i + 1]) {
            cut = i;
            break;
        }
    }
    if (cut == -1) return -1;
    for (int i = cut + 1; i < k-1; i++) {
        if (v[i] > v[i + 1]) return INF;
    }
    if (v[k - 1] > v[0]) return INF;
    return cut;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> k;
    f(i, k) {
        int x; cin >> x;
        n[i] = x;
        m[i] = -x;
    }
    int a = func(n);
    int b = func(m);
    
    if (a == INF && b == INF) cout << -1;
    else cout << min(a, b)+1;
    return 0;
}