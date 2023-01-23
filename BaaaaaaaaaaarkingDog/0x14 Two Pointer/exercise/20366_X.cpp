#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  for (auto& pt : s) cin >> pt;
  int mn = INT_MAX;
  sort(s.begin(), s.end());
  for (int i = 0; i < n - 3; ++i)
    for (int j = i + 3; j < n; ++j) {
      int st = i + 1, en = j - 1;
      while (st < en) {
        // (i, j)와 (st, en)으로 이루어진 두 눈사람의 키 차이를 살펴본다
        int diff = s[st] + s[en] - s[i] - s[j];
        mn = min(mn, abs(diff));
        // 차이는 절댓값으로 나타내기에 최대한 0에 가깝게 만들어야함
        if (diff < 0)
          st += 1;
        else
          en -= 1;
      }
    }
  cout << mn;
  return 0;
}