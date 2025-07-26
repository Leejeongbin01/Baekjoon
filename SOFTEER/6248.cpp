#include <iostream>
#include <vector>
using namespace std;

// easy

int N, M, S, T;
vector<int> dv[100001]; // 정방향
vector<int> rv[100001]; // 역방향

bool s_to_x[100001]; // 출근길: S → X 도달 가능
bool x_to_t[100001]; // 출근길: X → T 포함 가능 (역방향에서 T → X)
bool t_to_x[100001]; // 퇴근길: T → X 도달 가능
bool x_to_s[100001]; // 퇴근길: X → S 포함 가능 (역방향에서 S → X)

void dfs(int x, vector<int> graph[], bool visited[]) {
    if (visited[x]) return;
    visited[x] = true;
    for (int nxt : graph[x]) {
        dfs(nxt, graph, visited);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dv[a].push_back(b);   // 정방향
        rv[b].push_back(a);   // 역방향
    }

    cin >> S >> T;

    dfs(S, dv, s_to_x);   // 출근길: S → X
    dfs(T, rv, x_to_t);   // 출근길 포함: X → T
    dfs(T, dv, t_to_x);   // 퇴근길: T → X
    dfs(S, rv, x_to_s);   // 퇴근길 포함: X → S

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i == S || i == T) continue;
        if (s_to_x[i] && x_to_t[i] && t_to_x[i] && x_to_s[i]) {
            ans++;
        }
    }

    cout << ans -2 << "\n";
    return 0;
}
