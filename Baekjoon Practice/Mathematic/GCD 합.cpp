#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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
  int tc;
  cin >> tc;
  vector<int> v(101);

  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        sum += GCD(v[i], v[j]);
      }
    }
    cout << sum << '\n';
  }
  return 0;
}