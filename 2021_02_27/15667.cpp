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
    int k;
    cin >> k;
    if (k == 3) {
        cout << 1; return 0;
    }
    if (k == 1) {
        cout << 0; return 0;
    }
    k--;
    for (int i = 2; i <= k; i++) {
        if (i * i + i == k) {
            cout << i; return 0;
        }
    }
    
}