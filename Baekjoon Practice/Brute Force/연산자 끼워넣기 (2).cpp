#include <iostream>
#include <vector>

using namespace std;
vector<int> seq(11);
int n;
int a, s, m, d;
int maximum = -1000000001;
int minimum = 1000000001;

void update(int sum) {
  if (sum > maximum) {
    maximum = sum;
  }
  if (sum < minimum) {
    minimum = sum;
  }
  return;
}

void go(int index, int sum, int add, int sub, int mul, int div) {

  if (index == n) {
    update(sum);
    return;
  }
  if (add > 0) {
    go(index + 1, sum + seq[index], add - 1, sub, mul, div);
  }
  if (sub > 0) {
    go(index + 1, sum - seq[index], add, sub - 1, mul, div);
  }
  if (mul > 0) {
    go(index + 1, sum * seq[index], add, sub, mul - 1, div);
  }
  if (div > 0) {
    go(index + 1, sum / seq[index], add, sub, mul, div - 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> seq[i];
  }
  cin >> a >> s >> m >> d;
  go(1, seq[0], a, s, m, d);
  cout << maximum << '\n' << minimum << '\n';
  return 0;
}