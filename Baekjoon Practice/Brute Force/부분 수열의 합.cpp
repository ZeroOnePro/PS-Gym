#include <iostream>
#include <vector>

using namespace std;
int n;
int s;
int cnt = 0;
vector<int> seq(20);
void go(int index, int sum) {
  if (n == index) {
    if (sum == s) {
      cnt += 1;
    }
    return;
  }
  go(index + 1, sum + seq[index]);
  go(index + 1, sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  go(0, 0);
  if (s == 0)
    cnt -= 1;
  cout << cnt << '\n';
  return 0;
}