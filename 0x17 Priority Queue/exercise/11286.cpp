#include <bits/stdc++.h>

using namespace std;

// 비교함수(클래스)를 쓴다고 하면 cmp(앞에 위치해야하는 원소, 뒤에 위치해야하는
// 원소) = true가 되게끔 논리를 작성한다 a가 b보다 뒤로 가는 경우는 false를
// 리턴하게 하면 되겠지?

//  그리고 항상 cmp(a, a) = false를 만족해야한다, 아니면 런타임에러남

class cmp {
 public:
  bool operator()(int a, int b) {
    // 일반적인 sort와는 다르게 순서가 거꾸로감
    // 여기서는 우선순위가 낮을 수록 자식이 된다
    // a가 부모, b가 자식이다
    // a의 우선순위가 b의 우선순위보다 작은경우 a와 b의 자리가 뒤바뀌어야하는데
    // 여 문제에서는 우선순위가 절댓값이 작을 수록 높다
    if (abs(a) != abs(b)) return abs(a) > abs(b);
    return a > 0 && b < 0;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, query;
  priority_queue<int, vector<int>, cmp> pq;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> query;
    if (query == 0) {
      if (pq.empty()) {
        cout << 0 << '\n';
        continue;
      }
      cout << pq.top() << '\n';
      pq.pop();
    } else {
      pq.push(query);
    }
  }
  return 0;
}