#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int order = 0;
  int tc;
  cin >> tc;
  int n, m, prio;

  while (tc--) {

    order = 0;
    cin >> n >> m;

    queue<pair<int, int>> q; // 문서의 갯수, 인덱스 쌍
    priority_queue<int> pq;  // 우선순위 큐

    for (int j = 0; j < n; ++j) {
      cin >> prio;
      q.push({j, prio});
      pq.push(prio);
    }

    while (!q.empty()) {

      int index = q.front().first;
      int value = q.front().second;

      q.pop();

      // 궁금한문서와 중요도가 같고
      if (pq.top() == value) {
        pq.pop();
        order += 1;
        // 인덱스 마저 같다면
        if (index == m) {
          cout << order << '\n';
          break;
        }
      }
      // 큐 순환
      else {
        q.push({index, value});
      }
    }
  }
}