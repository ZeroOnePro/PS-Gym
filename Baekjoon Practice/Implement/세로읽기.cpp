#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<string> words(5, "");
  vector<int> words_len(5, 0);
  string ans = "";
  for (int i = 0; i < 5; ++i) {
    cin >> words[i];
    words_len[i] = words[i].length();
  }
  int j = 0;
  while (j <= 15) {
    for (int i = 0; i < 5; ++i) {
      if (j < words_len[i]) {
        ans += words[i].at(j);
      }
    }
    j += 1;
  }
  cout << ans << '\n';
  return 0;
}