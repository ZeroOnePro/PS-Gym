#include <bits/stdc++.h>

using namespace std;

class compare_class {
 public:
  // 부모가 자식보다 클 때
  // true일 때 swap 즉, 최소힙
  bool operator()(int a, int b) { return a > b; }
};

// false일 때 swap, 오름차순 정렬
bool compare_function(int a, int b) { return a < b; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> v = {5, 4, 3, 2, 1};
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int elem : v) pq.push(elem);
  sort(v.begin(), v.end(), greater<int>());
  cout << "compare function\n";
  for (int elem : v) {
    cout << elem << ' ';
  }
  cout << "\ncompare class\n";
  while (!pq.empty()) {
    cout << pq.top() << ' ';
    pq.pop();
  }

  return 0;
}