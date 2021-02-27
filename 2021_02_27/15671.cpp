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
const int dx[] = { -1, 0, 1, 0 ,1, 1, -1, -1 };
const int dy[] = { 0, -1, 0, 1 , -1, 1, -1, 1 };

const int mxn = 100001;
int n;
vector<pii> v;
char pan[6][6];
void func(pii p, int f) {
    char c, k;
    int x = p.first, y = p.second;
    if (f) {
        c = 'W';
    }
    else {
        c = 'B';
    }
    f(i, 8) {
        int flag = 0;
        int nx = x, ny = y;
        queue<pii> q;
        q.push({ x, y });
        while (1) {
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || ny < 0 || nx>5 || ny>5) break;
            if (pan[nx][ny] == '.') break;
            q.push({ nx, ny });
            if (pan[nx][ny] == c) {
                flag = 1; break;
            }
        }
        if (flag) {
            while (!q.empty()) {
                pii p = q.front(); q.pop();
                pan[p.first][p.second] = c;
            }
        }
    }

}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    f(i, n) {
        cin >> v[i].first >> v[i].second;
        v[i].first--, v[i].second--;
    }

    f(i, 6) f(j, 6) pan[i][j] = '.';
    pan[2][2] = pan[3][3] = 'W';
    pan[2][3] = pan[3][2] = 'B';
    f(i, n) {
        pii p = v[i];
        func(p, i % 2);
    }
    int bcnt = 0, wcnt = 0;
    f(i, 6) { 
        f(j, 6)
        {
            cout << pan[i][j];
            if (pan[i][j] == 'W') wcnt++;
            if (pan[i][j] == 'B') bcnt++;
        }
        cout << endl; 
    }
    if (wcnt > bcnt) cout << "White";
    else cout << "Black";
}