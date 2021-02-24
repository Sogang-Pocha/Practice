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

int n, m;
char jido[201][201];
int key[26], lock[26], visit[201][201];
pii start, fin;
queue<pii> pkey[26], plock[26];
vector<pii> root;


int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    f(i, n) cin >> jido[i];
    f(i, n) {
        f(j, m) {
            char c = jido[i][j];
            if (c == '@') {
                start = { i,j }; visit[i][j] = 1;
            }
            if (c == '!') fin = { i,j };
            //if (c >= 'a' && c <= 'z') pkey[c - 'a'].push_back({ i,j });
            //if (c >= 'A' && c <= 'Z') plock[c - 'A'].push_back({ i,j });
        }
    }
    
    root.push_back(start);
    queue<pii> q;
    q.push(start);
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        f(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visit[nx][ny]) continue;
            char c = jido[nx][ny];
            if (jido[nx][ny] == '#') continue;
            if (c == '!') {
                q = queue<pii>();
                root.push_back(fin);
                break;
            }
            if (c == '*') {
                visit[nx][ny] = 1;
                q.push({ nx, ny });
                root.push_back({ nx,ny });
            }
            if (c >= 'a' && c <= 'z') {
                visit[nx][ny] = 1;
                q.push({ nx, ny });
                root.push_back({ nx,ny });
                if (key[c - 'a']) continue;
                key[c - 'a'] = 1;
                while (!plock[c - 'a'].empty()) {
                    pii p = plock[c - 'a'].front();
                    plock[c - 'a'].pop();
                    int nnx = p.first;
                    int nny = p.second;
                    if (visit[nnx][nny]) continue;
                    q.push({ nnx,nny });
                    visit[nnx][nny] = 1;
                    root.push_back({ nnx,nny });
                }
            }
            if (c >= 'A' && c <= 'Z') {
                if (key[c - 'A']) {
                    visit[nx][ny] = 1;
                    lock[c - 'A'] = 1;
                    q.push({ nx,ny });
                    root.push_back({ nx,ny });
                }
                else plock[c - 'A'].push({ nx,ny });
            }
        }
    }
    cout << root.size() << '\n';
    for (pii p : root) {
        cout << p.first + 1 << ' ' << p.second+1 << '\n';
    }
    return 0;
}