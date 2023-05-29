#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool permutation_next(vector<int> &seq, int n) {
  int i = n - 1;
  while (i > 0 && seq[i - 1] >= seq[i]) {
    i -= 1;
  }
  if (i <= 0)
    return false;
  int j = n - 1;
  while (seq[j] <= seq[i - 1]) {
    j -= 1;
  }
  swap(seq[i - 1], seq[j]);
  j = n - 1;
  while (i < j) {
    swap(seq[i], seq[j]);
    i += 1;
    j -= 1;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  if (permutation_next(seq, n)) {
    for (int i = 0; i < n; ++i) {
      cout << seq[i] << ' ';
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}