#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  long long change;
  cin >> n >> change;
  vector<long long> coin(11);
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
  }
  // selection procedure -> 거스름돈보다는 작은 최대 크기 동전 부터 고름
  // feasibility check -> 이것을 골랐을 때, 잔돈을 초과하니?
  // solution check -> 잔돈하고 고른 것들의 합하고 같니?
  long long sum = 0;
  int cnt = 0;
  for (int i = n - 1; i >= 0;) {

    sum += coin[i];
    if (sum > change) {
      sum -= coin[i];
      --i;
    }

    else if (sum == change) {
      break;
    }

    else {
      cnt++;
    }
  }

  cout << cnt + 1 << '\n';

  return 0;
}