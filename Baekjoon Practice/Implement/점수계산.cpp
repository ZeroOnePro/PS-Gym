#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<pair<int, int>> score(8);
  for (int i = 0; i < 8; ++i) {
    score[i].second = i + 1;
    cin >> score[i].first;
  }
  sort(score.begin(), score.end(),
       [&score](pair<int, int> a, pair<int, int> b) {
         return a.first > b.first;
       });
  // 0, 1, 2, 3, 4
  int total = 0;
  vector<int> problem_num(5, 0);
  for (int i = 0; i < 5; ++i) {
    total += score[i].first;
    problem_num.push_back(score[i].second);
  }
  cout << total << '\n';
  sort(problem_num.begin(), problem_num.end());
  for_each(problem_num.begin(), problem_num.end(), [&problem_num](int num) {
    if (num != 0)
      cout << num << '\n';
  });
  return 0;
}