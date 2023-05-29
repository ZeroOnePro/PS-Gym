#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    long long int a, b;
    cin >> a >> b;
    long long int result = 1;
    int i = 0;
    // 10으로 나눈 나머지는 1의 자리를 뜻한다.
    while (i < b) {
      result = (result * a) % 10;
      i += 1;
    }
    if (!result)
      result = 10;
    cout << result << '\n';
  }
  return 0;
}