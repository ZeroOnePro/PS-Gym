#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  vector<int> score;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    score.push_back(in);
  }
  sort(score.begin(), score.end());
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int target = -score[i] - score[j];
      ans += upper_bound(score.begin() + j + 1, score.end(), target) -
             lower_bound(score.begin() + j + 1, score.end(), target);
    }
  }
  cout << ans;
  return 0;
}