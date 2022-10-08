#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<int> seq;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    seq.push_back(in);
  }
  if (n == 1) {
    cout << seq[0];
    return 0;
  }
  sort(seq.begin(), seq.end());
  int cur = 0;
  int ans = 0;
  while (cur <= n - 1 && seq[cur] <= 0) {
    // 묶음
    if (cur <= n - 2 && seq[cur] + seq[cur + 1] < seq[cur] * seq[cur + 1]) {
      ans += (seq[cur] * seq[cur + 1]);
      cur += 2;
    } else {
      ans += seq[cur];
      cur += 1;
    }
  }
  int st = cur;
  cur = n - 1;
  // cout << st << ' ' << n;
  while (cur >= st) {
    // 묶음
    if (cur - 1 >= st && seq[cur] + seq[cur - 1] < seq[cur] * seq[cur - 1]) {
      ans += (seq[cur] * seq[cur - 1]);
      cur -= 2;
    } else {
      ans += seq[cur];
      cur -= 1;
    }
  }
  cout << ans;
  return 0;
}