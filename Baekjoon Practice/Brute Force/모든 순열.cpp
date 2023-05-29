#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 1; i <= n; ++i) {
    seq[i - 1] = i;
  }
  do {
    for (int i = 0; i < n; ++i) {
      cout << seq[i] << ' ';
    }
    cout << '\n';
  } while (next_permutation(seq.begin(), seq.end()));
  return 0;
}