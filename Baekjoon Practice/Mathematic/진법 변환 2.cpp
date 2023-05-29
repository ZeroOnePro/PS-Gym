#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<char> p(37);

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  int b;
  cin >> n >> b;
  stack<char> ans;

  for (int i = 0; i <= 25; ++i) {
    p[i] += 'A' + i;
  }

  while (n > 0) {
    int tmp = n % b;
    if (tmp >= 10) {
      ans.push(p[tmp - 10]);
    } else {
      ans.push(tmp + '0');
    }
    n /= b;
  }

  while (!ans.empty()) {
    cout << ans.top();
    ans.pop();
  }

  return 0;
}