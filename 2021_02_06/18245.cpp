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
    string s;
    int jump = 2;
    while (1) {
        getline(cin, s);
        if (s == "Was it a cat I saw?") break;
        for (int i = 0; i < s.size(); i += jump) {
            cout << s[i];
        }
        cout << '\n';
        jump++;
    }
}