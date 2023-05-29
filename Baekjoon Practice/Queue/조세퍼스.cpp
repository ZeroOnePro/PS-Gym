#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, k;

  cin >> n >> k;

  queue<int> q;

  for (int i = 1; i <= n; ++i) {
    q.push(i);
  }

  cout << '<';
  // 서큘러 큐 앞에꺼 꺼내서 다시 뒤로 넣고 입력만큼(k) 반복
  while (!q.empty()) {
    for (int j = 1; j < k; ++j) {
      q.push(q.front());
      q.pop();
    }
    // n 개의 숫자가 출력
    cout << q.front();
    if (q.size() != 1)
      cout << ',' << ' ';
    q.pop();
  }

  cout << '>' << '\n';

  return 0;
}