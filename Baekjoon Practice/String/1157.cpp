#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> alpha(26);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string str;
  cin >> str;
  for (char ch : str) {
    alpha[toupper(ch) - 'A'] += 1;
  }
  int ans = alpha[0];
  int index = 0;
  for (int i = 0; i < 26; ++i) {
    if (ans < alpha[i]) {
      ans = alpha[i];
      index = i;
    }
  }
  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (ans == alpha[i]) {
      cnt += 1;
    }
  }
  if (cnt >= 2) {
    cout << "?" << '\n';
    return 0;
  }
  cout << (char)(index + 'A') << '\n';

  return 0;
}