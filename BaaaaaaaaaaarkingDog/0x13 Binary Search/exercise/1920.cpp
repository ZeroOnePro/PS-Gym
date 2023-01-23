#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n;

bool binary_search(int target) {
  int st = 0;
  int en = n - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (a[mid] < target)
      st = mid + 1;
    else if (a[mid] > target)
      en = mid - 1;
    else
      return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int m;
  cin >> m;
  while (m--) {
    int target;
    cin >> target;
    cout << binary_search(target) << '\n';
  }
  return 0;
}