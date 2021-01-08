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



int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> ans(q + 1), duck(q + 1), is_con(n+1);
    f(i, q) {
        cin >> duck[i + 1];
    }
    for (int i = 1; i <= q; i++) {
        int x = duck[i];
        stack<int> root;
        while (x) {
            root.push(x);
            x /= 2;
        }
        int flag = 0;
        while(!root.empty()) {
            int t = root.top(); root.pop();
            
            if (is_con[t]) {
                ans[i] = t;
                flag = 1;
                break;
            }
        }
        
        if (!flag) is_con[duck[i]] = 1;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}