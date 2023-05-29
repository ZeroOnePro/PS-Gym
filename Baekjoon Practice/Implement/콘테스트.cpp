#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> w(10, 0);
  vector<int> k(10, 0);
  for (int i = 0; i < 20; i++)
    i < 10 ? cin >> w[i] : cin >> k[i - 10];
  sort(w.begin(), w.end());
  sort(k.begin(), k.end());
  cout << w[7] + w[8] + w[9] << ' ' << k[7] + k[8] + k[9];
  return 0;
}