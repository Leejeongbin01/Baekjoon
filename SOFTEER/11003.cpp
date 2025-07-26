#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
long long K;
int arr[100001];

// X 높이 피라미드를 만들 수 있는지 확인
bool can_achieve(long long X) {
    vector<long long> diff_a(N + 5, 0), diff_b(N + 5, 0);

    for (int j = 1; j <= N; ++j) {
        long long r = X - arr[j];
        if (r <= 0) continue;

        int L = max(1LL, j - r + 1);
        int R = min((long long)N, j + r - 1);

        // [L, j] 구간에 대해 f(i) = i - j + r
        if (L <= j) {
            diff_a[L] += 1;
            diff_a[j + 1] -= 1;
            diff_b[L] += (r - j);
            diff_b[j + 1] -= (r - j);
        }

        // [j, R] 구간에 대해 f(i) = -i + (r + j)
        if (j <= R) {
            diff_a[j] -= 1;
            diff_a[R + 1] += 1;
            diff_b[j] += (r + j);
            diff_b[R + 1] -= (r + j);
        }

        // i = j에서 중복되는 r 제거
        diff_b[j] -= r;
        diff_b[j + 1] += r;
    }

    long long min_cost = LLONG_MAX;
    long long curr_a = 0, curr_b = 0;

    for (int i = 1; i <= N; ++i) {
        curr_a += diff_a[i];
        curr_b += diff_b[i];
        long long cost = curr_a * i + curr_b;
        min_cost = min(min_cost, cost);
    }

    return min_cost <= K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int max_h = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        max_h = max(max_h, arr[i]);
    }

    // 이분 탐색: 만들 수 있는 최대 높이 X 찾기
    long long lo = max_h;
    long long hi = max_h + K;
    long long answer = max_h;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can_achieve(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}