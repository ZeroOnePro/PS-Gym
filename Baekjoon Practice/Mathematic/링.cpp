#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i < n; ++i) {
    cout << v[0] / GCD(v[0], v[i]) << '/' << v[i] / GCD(v[0], v[i]) << '\n';
  }
  return 0;
}