#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> seq(5);
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> seq[i];
    sum += seq[i];
  }
  sort(seq.begin(), seq.end());
  cout << sum / 5 << '\n' << seq[2] << '\n';
  return 0;
}