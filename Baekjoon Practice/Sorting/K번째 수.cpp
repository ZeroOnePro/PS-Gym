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
  vector<int> seq(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  sort(seq.begin(), seq.end());
  cout << seq[k - 1] << '\n';
  return 0;
}