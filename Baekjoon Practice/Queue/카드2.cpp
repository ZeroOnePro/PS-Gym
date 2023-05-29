#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;

  queue<int> q;

  for (int i = 1; i <= n; i += 1) {
    q.push(i);
  }

  while (q.size() != 1) {
    // 제일 위의 카드 꺼내고
    q.pop();
    // 그 다음 위의 카드를 맨 밑으로
    q.push(q.front());
    q.pop();
  }

  cout << q.front() << '\n';

  return 0;
}