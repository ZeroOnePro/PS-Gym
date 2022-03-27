#include <bits/stdc++.h>

using namespace std;

void hanoi(int start, int end, int n) {
  if (n == 1) {
    cout << start << ' ' << end << '\n';
    return;
  }
  // n-1개의 원판을 시작에서 중간으로 옮김
  hanoi(start, 6 - start - end, n - 1);
  cout << start << ' ' << end << '\n';
  // n-1개의 원판을 중간에서 끝으로 옮김
  hanoi(6 - start - end, end, n - 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';
  hanoi(1, 3, n);
  return 0;
}