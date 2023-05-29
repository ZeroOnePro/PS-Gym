#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> seq_a(n, 0);
  vector<int> seq_b(n, 0);
  for (int i = 0; i < 2 * n; ++i) {
    i < n ? cin >> seq_a[i] : cin >> seq_b[i - n];
  }
  sort(seq_a.begin(), seq_a.end());
  sort(seq_b.begin(), seq_b.end(), [&seq_b](int a, int b) { return a > b; });
  for (int i = 0; i < k; ++i) {
    swap(seq_a[i], seq_b[i]);
  }
  int sum = 0;
  for (int i : seq_a) {
    sum += i;
  }
  cout << sum << '\n';
  return 0;
}