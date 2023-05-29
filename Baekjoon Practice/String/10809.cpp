#include <iostream>
#include <vector>

using namespace std;

vector<int> alpha(26, -1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string input;
  cin >> input;
  int index = 0;
  for (char ch : input) {
    if (alpha[ch - 'a'] == -1) {
      alpha[ch - 'a'] = index;
    }
    index += 1;
  }
  for (int i : alpha) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}