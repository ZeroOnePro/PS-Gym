#include <cmath>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int r, e, c;
    cin >> r >> e >> c;
    if (r > e - c) {
      cout << "do not advertise\n";
    } else if (r == e - c) {
      cout << "does not matter\n";
    } else {
      cout << "advertise\n";
    }
  }
  return 0;
}