#include <bits/stdc++.h>

using namespace std;

// 크기 지정 없이 초기화 했을 때 vector의 size가 어떻게 되는지 테스트

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> test;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) test.push_back(i);
  cout << test.size() << '\n';
  return 0;
}