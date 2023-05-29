#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq_a;
  vector<int> seq_b;
  for (int i = 0; i < 2 * n; ++i) {
    int temp;
    cin >> temp;
    if (i < n) {
      seq_a.push_back(temp);
    } else {
      seq_b.push_back(temp);
    }
  }

  sort(seq_a.begin(), seq_a.end());
  sort(seq_b.begin(), seq_b.end(),
       [&seq_b](int a, int b) -> bool { return a > b; });
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += seq_a[i] * seq_b[i];
  }
  cout << sum << '\n';
  return 0;
}