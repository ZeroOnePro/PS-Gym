#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> t(15);
vector<int> p(15);
int ans = 0;
int n;

void go(int day, int sum) {
  if (day == n) {
    if (ans < sum) {
      ans = sum;
    }
    return;
  }
  if (day > n) {
    return;
  }
  go(day + t[day], sum + p[day]);
  go(day + 1, sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    cin >> p[i];
  }
  go(0, 0);
  cout << ans << '\n';
  return 0;
}