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
#include <map>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using ll = long long;

const int MOD = 1e9 + 7, INF = 1e9+100;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


int n;
struct s {
    int sum, x, y;
};

bool cmp(s a, s b) {
    return a.sum < b.sum;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> snow(n + 1);
    vector<s> sum(n * (n-1)/2);
    map<int, int> num;
    f(i, n) { 
        cin >> snow[i]; 
        num[snow[i]]++;
    }
    int idx = 0, ans=INF*2;
    f(i, n) {
        for (int j = i + 1; j < n; j++) {
            sum[idx++] = { snow[i] + snow[j], i, j };
        }
    }
    sort(all(sum), cmp);
    f(i, idx) {
        for (int j = i + 1;j<idx; j++) {
            if (sum[i].x == sum[j].x || sum[i].x == sum[j].y) continue;
            if (sum[i].y == sum[j].x || sum[i].y == sum[j].y) continue;
            ans = min(ans, sum[j].sum - sum[i].sum);
            break;
        }
    }
    cout << ans;
    return 0;
}