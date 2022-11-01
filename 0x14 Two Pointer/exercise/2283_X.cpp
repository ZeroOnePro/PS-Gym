#include <bits/stdc++.h>

using namespace std;

const int range = 1e6 + 1;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> len(range);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    // 구간 내에 선이 들어오는 구간은 a+1 ~ b까지
    // 선 하나에 커서 이동시켜가면서 이해하면 편함
    len[a + 1] += 1;
    len[b + 1] -= 1;
  }
  // 점 a에서 제외되는 선의 개수 a-1까지 선들의 길이의 합 + a ~ a-1에 포함된
  // 선의 개수
  for (int i = 1; i < range; ++i) len[i] += len[i - 1];
  int st = 0, en = 0, sum = 0;
  while (en < range) {
    if (sum < k)
      sum += len[++en];
    else if (sum > k)
      sum -= len[++st];
    else {
      cout << st << ' ' << en;
      return 0;
    }
  }
  cout << "0 0";
  return 0;
}