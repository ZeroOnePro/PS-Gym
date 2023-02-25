#include <bits/stdc++.h>

using namespace std;

const int range = 15;

int n, mx = INT_MIN, mn = INT_MAX;
int op[range];
int seq[range];
int copied[range];
int is_used[4];

void all_case(int cur) {
  if (cur == n - 1) {
    // 여기서 계산하고 최대 최소 구하기
    copy(seq, seq + range, copied);
    for (int i = 0; i < n - 1; ++i) {
      // cout << op[i] << ' ';
      switch (op[i]) {
        case 0:
          copied[i + 1] = copied[i] + copied[i + 1];
          break;
        case 1:
          copied[i + 1] = copied[i] - copied[i + 1];
          break;
        case 2:
          copied[i + 1] = copied[i] * copied[i + 1];
          break;
        case 3:
          copied[i + 1] = copied[i] / copied[i + 1];
          break;
      }
    }
    mn = min(mn, copied[n - 1]);
    mx = max(mx, copied[n - 1]);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (is_used[i] == 0) continue;
    if (seq[cur + 1] == 0 && i == 3) continue;
    op[cur] = i;
    is_used[i] -= 1;
    all_case(cur + 1);
    is_used[i] += 1;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> seq[i];
  for (int i = 0; i < 4; ++i) cin >> is_used[i];
  all_case(0);
  cout << mx << '\n' << mn;
  return 0;
}