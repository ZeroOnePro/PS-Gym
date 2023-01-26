#include <bits/stdc++.h>

using namespace std;

const int range = 1e6;

int t, n, m, k;
int house[range];
int csum[range];
bool is_used[range];

void input() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> house[i];
    csum[i] = house[i];
  }
  for (int i = 0; i < m; ++i) csum[n + i] = house[i];  // circular
}

void init() {
  fill(house, house + n, 0);
  fill(csum, csum + n, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    input();
    // M개의 연속된 집을 정했을 때 가능한 케이스인지 체크
    // O(NM)이면 시간초과이므로 누적합 미리 구하기
    // 구간 [i, j]의 돈의 합은 sum[j] - sum[i-1]
    // j = m - 1 + i
    /**
     * 고려 못한 케이스
     * 모두 같은경우 중복을 허용했다
     * 1
     * 3 3 5
     * 1 1 1
     * 답 :1
     * 출력 : 3
     * 1 - 2 - 3
     * 2 - 3 - 1
     * 3 - 1 - 2
     * N == M일 때만 이런게 생긴다
     * 모두 같은 경우임에도 3이 출력
     */
    int cnt = 0;
    for (int i = 1; i < m + n - 1; ++i) csum[i] += csum[i - 1];
    for (int i = 0; i < n; ++i) {
      int local_csum = 0, en = m - 1 + i, st = i - 1;
      if (i == 0) local_csum = csum[en];
      local_csum = csum[en] - csum[st];
      if (local_csum < k) cnt += 1;
    }
    // 같은게 n개 생김, 고려못한 케이스 참조
    if (n == m) cnt /= n;
    cout << cnt << '\n';
    init();
  }
  return 0;
}