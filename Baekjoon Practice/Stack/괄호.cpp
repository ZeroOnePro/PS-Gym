#include <iostream>
#include <string>

using namespace std;

string valid(string str) {
  int cnt = 0;

  for (char ch : str) {
    if (ch == '(') {
      cnt += 1;
    } else {
      cnt -= 1;
    }

    if (cnt < 0) {
      return "NO";
    }
  }

  if (cnt == 0) {
    return "YES";
  } else {
    return "NO";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  string str;

  cin >> tc;

  while (tc--) {
    cin >> str;
    cout << valid(str) << '\n';
  }

  return 0;
}