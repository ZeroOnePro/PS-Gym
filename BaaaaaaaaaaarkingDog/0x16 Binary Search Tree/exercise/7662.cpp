#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  char q;
  int test_case, k, arg;
  multiset<int> ms;
  cin >> test_case;
  while (test_case--) {
    cin >> k;
    while (k--) {
      cin >> q >> arg;
      if (ms.empty() and q == 'D') continue;
      if (q == 'I')
        ms.insert(arg);
      else {
        if (arg == 1) {
          ms.erase(prev(ms.end()));
        } else {
          ms.erase(ms.begin());
        }
      }
    }
    if (ms.empty())
      cout << "EMPTY\n";
    else
      cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    ms.clear();
  }
  return 0;
}