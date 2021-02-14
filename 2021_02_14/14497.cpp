#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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

using namespace std;
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

int R, C, x, y, x2, y2;
char grid[305][305];
int visit[305][305];
queue<pair<pii, int>> qu;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> R >> C >> x >> y >> x2 >> y2;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    if (x == x2 && y == y2) {
        cout << 0;
        return 0;
    }

    qu.push({ {x, y}, 1 });
    fill(visit[0], visit[0] + 305 * 305, INF);
    visit[x][y] = 0;
    
    while (!qu.empty()) {
        pii cur = qu.front().first;
        int lv = qu.front().second;
        qu.pop();

        if (cur.first == x2 && cur.second == y2) {
            visit[x2][y2] = min(visit[x2][y2], lv);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            int nlv = lv;

            if (0 < nr && nr <= R && 0 < nc && nc <= C) {
                if (visit[nr][nc] <= lv) continue;
                //cout << nr << " " << nc << " "<<lv<< endl;
                visit[nr][nc] = lv;
                if (grid[nr][nc] == '1') nlv++;
                qu.push({ {nr, nc}, nlv });
            }
        }
    }

    cout << visit[x2][y2];

    return 0;
}