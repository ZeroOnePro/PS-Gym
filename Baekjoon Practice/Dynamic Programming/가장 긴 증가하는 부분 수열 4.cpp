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
  vector<int> dp(n + 1, 1);
  vector<int> index(n + 1);

  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
    index[i] = i;
  }

  int max = 1;
  int end = 0;

  bool flag = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        index[i] = j;
      }
    }
    if (max < dp[i]) {
      max = dp[i];
      end = i;
    }
  }

  cout << max << '\n';
  // LIFO => 넣은순서 반대로 출력!!!!!, 왜 공부해놓고 써먹질못하니
  // 잘 기억하도록 ^오^
  stack<int> lis;
  int j = end;
  while (j != index[j]) {
    lis.push(seq[j]);
    j = index[j];
  }

  lis.push(seq[j]);

  while (!lis.empty()) {
    cout << lis.top() << ' ';
    lis.pop();
  }

  return 0;
}