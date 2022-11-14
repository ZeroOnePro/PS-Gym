#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  // 원소들을 오름차순 정렬했을 때 중앙을 잘라 뒷부분 저장(즉 큰 수들이 최소
  // 힙에 담김)
  priority_queue<int, vector<int>, greater<int>> min_pq;
  // 원소들을 오름차순 정렬했을 때 중앙을 잘라 앞부분 저장(즉 작은 수들이 최대
  // 힙에 담김)
  priority_queue<int> max_pq;
  // 중간값이란 큰거와 작은거 사이에 낀 값
  cin >> n;
  while (n--) {
    int in;
    cin >> in;
    if (max_pq.size() <= min_pq.size())
      max_pq.push(in);
    else
      min_pq.push(in);
    // min_pq의 크기가 max_pq의 크기와 같거나 1작을 수 있으므로 비어있는지 확인
    // 필요
    if (!min_pq.empty() && max_pq.top() > min_pq.top()) {
      // swap
      // 이게 필요한 이유는 원소가 정렬되어 들어오는게 아니기때문에
      // 두 큐의 크기가 같은 상황에서 2 1이 연달아 들어오면 max로 2가 가고
      // min으로 1이 가기 때문에 큰 수가 min에 저장되고 작은 수가 max에
      // 저장되야하는 규칙에 어긋난다
      min_pq.push(max_pq.top());
      max_pq.pop();
      max_pq.push(min_pq.top());
      min_pq.pop();
    }
    cout << max_pq.top() << '\n';
  }
  return 0;
}