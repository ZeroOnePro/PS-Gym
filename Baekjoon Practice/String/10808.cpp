#include <iostream>
#include <vector>

using namespace std;

vector<int> alpha(26);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string input;
  cin >> input;
  for (char ch : input) {
    alpha[ch - 'a'] += 1;
  }
  for (int i : alpha) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}