#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  list<int> seq;
  for (int i = 1; i <= 10; ++i) seq.push_back(i);
  auto cur = seq.end();
  cur--;
  if (cur == prev(seq.end())) cout << "end\n";
  return 0;
}