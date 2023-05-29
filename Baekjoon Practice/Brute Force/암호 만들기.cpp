#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool check(string &str) {
  int v = 0;
  int c = 0;
  for (char ch : str) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      v += 1;
    } else {
      c += 1;
    }
  }
  return v >= 1 && c >= 2;
}

void go(int n, int i, string password, vector<char> &p) {
  if (password.length() == n) {
    if (check(password)) {
      cout << password << '\n';
    }
    return;
  }
  int size = p.size();
  if (i >= size)
    return;
  go(n, i + 1, password + p[i], p);
  go(n, i + 1, password, p);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int l, c;
  cin >> l >> c;
  vector<char> p(c);
  string str = "";
  for (int i = 0; i < c; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  go(l, 0, str, p);
  return 0;
}