#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, input;
  cin >> n;
  int cute = 0, not_cute = 0;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    input ? cute += 1 : not_cute += 1;
  }
  max(cute, not_cute) == not_cute ? cout << "Junhee is not cute!\n"
                                  : cout << "Junhee is cute!\n";
  return 0;
}