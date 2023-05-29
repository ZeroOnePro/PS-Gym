#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int absolute(int x) { return x < 0 ? -x : x; }

int calc(vector<int> &a, int n) {
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += absolute(a[i] - a[i + 1]);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  sort(a.begin(), a.end());
  do {
    if (ans < calc(a, n)) {
      ans = calc(a, n);
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << '\n';
  return 0;
}