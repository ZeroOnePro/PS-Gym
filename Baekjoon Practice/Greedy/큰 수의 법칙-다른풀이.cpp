#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 공통되는 부분을 묶는다 -> 반복을 지양한다.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> seq(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  sort(seq.begin(), seq.end());
  int big_num = 0;
  int cnt = (int)(m / (k + 1)) * k + m % (k + 1);
  big_num += cnt * seq[n - 1];
  big_num += (m - cnt) * seq[n - 2];
  cout << big_num << '\n';
  return 0;
}