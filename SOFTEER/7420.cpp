#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int INF = 1e9;

int N, M;
int arr[100][100];
int giftX, giftY;
map<int, vector<pair<int, int>>> m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, INF));
    q.push({sx, sy});
    dist[sx][sy] = 0;

    set<int> used_teleport;

    while (!q.empty()) {
        int qsize = q.size();
        set<int> cur_teleport;
        vector<pair<int, int>> teleport_from;

        for (int i = 0; i < qsize; ++i) {
            auto [x, y] = q.front(); q.pop();
            if (x == ex && y == ey) return dist[x][y];

            // 상하좌우 이동
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && arr[nx][ny] != -1 && dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    q.push({nx, ny});
                }
            }

            // 텔레포트 후보 저장
            if (arr[x][y] >= 10 && !used_teleport.count(arr[x][y])) {
                cur_teleport.insert(arr[x][y]);
                teleport_from.push_back({x, y});
            }
        }

        // 레벨 끝나고 텔레포트 처리
        for (int tnum : cur_teleport) {
            used_teleport.insert(tnum);
        }

        for (auto& [x, y] : teleport_from) {
            int tnum = arr[x][y];
            for (auto& [tx, ty] : m[tnum]) {
                if (dist[tx][ty] > dist[x][y] + 1) {
                    dist[tx][ty] = dist[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 10) {
                m[arr[i][j]].push_back({i, j});
            }
            if (arr[i][j] == -2) {
                giftX = i;
                giftY = j;
            }
        }
    }

    int cnt1 = bfs(1, 1, giftX, giftY);
    int cnt2 = bfs(giftX, giftY, N, M);

    if (cnt1 == -1 || cnt2 == -1) cout << -1 << '\n';
    else cout << cnt1 + cnt2 << '\n';

    return 0;
}
