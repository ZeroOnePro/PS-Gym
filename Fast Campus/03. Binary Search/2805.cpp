#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<long long> tree;

bool possible(long long len) {
  long long tot = 0;
  for (long long i : tree)
    if (i > len) tot += (i - len);
  return tot >= m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    long long len;
    cin >> len;
    tree.push_back(len);
  }
  long long st = 0, en = 2 * 1e9 + 1;
  while (st < en) {
    long long mid = (st + en + 1) / 2;
    if (possible(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}