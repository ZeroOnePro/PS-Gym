#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    x -= 1;
    y -= 1;
    int end = M * N;
    bool flag = false;
    for (int start = x; start <= end; start += M) {
      if (start % N == y && start % M == x) {
        flag = true;
        cout << start + 1 << '\n';
        break;
      }
    }
    if (!flag) {
      cout << -1 << '\n';
    }
  }
  return 0;
}