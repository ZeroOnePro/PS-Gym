#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n), lis;
  for (auto& pt : s) cin >> pt;
  lis.push_back(0);  // 편의상 추가
  for (int e : s) {
    if (lis.back() < e)
      lis.push_back(e);
    else {
      int lb = lower_bound(lis.begin(), lis.end(), e) - lis.begin();
      lis[lb] = e;
    }
  }
  cout << lis.size() - 1;
  return 0;
}