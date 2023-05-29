#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;

  vector<int> seq(n + 1);
  vector<int> nge(n + 1, -1);

  for (int i = 1; i <= n; i++) {
    cin >> seq[i];
  }

  stack<int> s;

  s.push(1);

  for (int i = 2; i <= n; i++) {
    while (!s.empty() && seq[s.top()] < seq[i]) {
      // 오큰수 찾음
      nge[s.top()] = seq[i];
      s.pop();
    }
    // 현재 인덱스에서 다시시작
    s.push(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << nge[i] << ' ';
  }

  cout << '\n';
  return 0;
}