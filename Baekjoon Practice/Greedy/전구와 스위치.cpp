#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cnt = 0;
string a, b;
void toggle(char *elem) { *elem - '0' ? *elem = '0' : *elem = '1'; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    char ch;
    cin >> ch;
    i < n ? a.push_back(ch) : b.push_back(ch);
  }
  // 0과 n-1일 때만 다르고 나머지는 i-1,i,i+1을 검사
  for (int i = 0; i < n; ++i) {
    // cout << a << '\n';
    if (i == 0) {
      if (a[i] == b[i] && a[i + 1] == b[i + 1])
        continue;
      else {
        cnt += 1;
        toggle(&a[i]);
        toggle(&a[i + 1]);
      }
    } else if (i == n - 1) {
      if (a[i - 1] == b[i - 1] && a[i] == b[i])
        continue;
      else {
        cnt += 1;
        toggle(&a[i - 1]);
        toggle(&a[i]);
      }
    } else {
      if (a[i - 1] == b[i - 1] && a[i] == b[i] && a[i + 1] == b[i + 1])
        continue;
      else {
        cnt += 1;
        toggle(&a[i - 1]);
        toggle(&a[i]);
        toggle(&a[i + 1]);
      }
    }
  }
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      flag = false;
      break;
    }
  }
  flag ? cout << cnt << '\n' : cout << -1 << '\n';
  return 0;
}
