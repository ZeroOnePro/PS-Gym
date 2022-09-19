#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 3;
  vector<int> seq(3);
  while (n--) {
    int input;
    cin >> input;
    seq[abs(n - 2)] = input;
  }
  sort(seq.begin(), seq.end());
  for (int elem : seq) {
    cout << elem << ' ';
  }
  return 0;
}