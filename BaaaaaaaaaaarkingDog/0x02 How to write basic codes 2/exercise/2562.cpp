#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int maximum = 0, index = 0;
  ;
  for (int i = 1; i <= 9; ++i) {
    int input;
    cin >> input;
    if (maximum < input) {
      maximum = input;
      index = i;
    }
  }
  cout << maximum << '\n' << index;
  return 0;
}

// 별해 - max_element를 이용
// cout << *max_element(a, a + 9) << '\n';
// cout << max_element(a, a + 9) - a + 1;