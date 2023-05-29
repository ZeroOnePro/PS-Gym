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
  vector<int> seq(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  sort(seq.begin(), seq.end(), [&seq](int a, int b) { return a > b; });
  for (int i : seq) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
