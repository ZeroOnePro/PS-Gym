#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int k;

  cin >> k;
  stack<int> s;
  while (k--) {
    int i;
    cin >> i;
    if (i != 0) {
      s.push(i);
    } else {
      if (!s.empty()) {
        s.pop();
      }
    }
  }

  int sum = 0;
  while (!s.empty()) {
    sum += s.top();
    s.pop();
  }

  cout << sum;

  return 0;
}