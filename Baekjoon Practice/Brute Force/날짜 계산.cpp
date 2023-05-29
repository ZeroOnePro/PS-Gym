#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int E, S, M;
  cin >> E >> S >> M;
  E -= 1;
  S -= 1;
  M -= 1;
  int ans = 0;
  for (int i = 0; i <= 10000; ++i) {
    if (i % 15 == E && i % 28 == S && i % 19 == M) {
      ans = i;
      break;
    }
  }
  ans += 1;
  cout << ans << '\n';
  return 0;
}