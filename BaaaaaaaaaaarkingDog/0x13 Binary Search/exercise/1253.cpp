#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<int> a;

bool decision(int idx) {
  int l = 0, r = n - 1;
  int target = a[idx];
  while (l < r) {
    if (l == idx)
      l++;
    else if (r == idx)
      r--;
    else {
      // 최소 + 최대 < 0, 최소의 입장에선 최대 원소 제외 다른 임의의 원소와
      // 합을 해도 더 작은 음수가 된다 최소는 쌍을 찾은 것
      if (a[l] + a[r] < target) l++;
      // 최소 + 최대 > 0, 최대의 입장에선 최소 원소 제외 다른 임의의 원소와
      // 합을 해도 더 큰 양수가 된다 최대는 쌍을 찾은 것
      else if (a[l] + a[r] > target)
        r--;
      else
        return true;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;
    a.push_back(e);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i)
    if (decision(i)) ans += 1;
  cout << ans;
  return 0;
}