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
    int a[5];
    f(i, 5) cin >> a[i];
    int d = 0;
    while (1) {
        int x = 0, y = 0, z = 0;
        if (a[0] > 0) {
            x = 1; a[0]--;
        }
        if (a[2] > 0) {
            y = 1; a[2]--;
        }
        if (a[4] > 0) {
            z = 1; a[4]--;
        }
        if (x && y && z) {
            d++;
            continue;
        }
        if (!x) {
            if (a[1] > 0) {
                x = 1; a[1]--;
            }
        }
        if (!z) {
            if (a[3] > 0) {
                z = 1; a[3]--;
            }
        }
        if (!y) {
            if (a[1] > 0 || a[3] > 0) {
                if (a[1] > a[3]) {
                    y = 1; a[1]--;
                }
                else {
                    y = 1; a[3]--;
                }
            }
        }
        if (x && y && z) {
            d++;
            continue;
        }
        break;
    }
    cout << d;
}