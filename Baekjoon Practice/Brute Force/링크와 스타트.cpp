#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> s(20, vector<int>(20));

int absolute(int x) { return x < 0 ? -x : x; }

int go(int index, vector<int> &first, vector<int> &second) {
  // 정답의 후보를 찾은 경우
  if (index == n) {
    if (!first.size())
      return -1;
    if (!second.size())
      return -1;
    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < (int)first.size(); ++i) {
      for (int j = 0; j < (int)first.size(); ++j) {
        if (i == j)
          continue;
        t1 += s[first[i]][first[j]];
      }
    }
    for (int i = 0; i < (int)second.size(); ++i) {
      for (int j = 0; j < (int)second.size(); ++j) {
        if (i == j)
          continue;
        t2 += s[second[i]][second[j]];
      }
    }
    return absolute(t1 - t2);
  }
  // 다음단계 호출
  int ans = -1;
  first.push_back(index);
  int t1 = go(index + 1, first, second);
  if (ans == -1 || (t1 != -1 && ans > t1)) {
    ans = t1;
  }
  first.pop_back();

  second.push_back(index);
  int t2 = go(index + 1, first, second);
  if (ans == -1 || (t2 != -1 && ans > t2)) {
    ans = t2;
  }
  second.pop_back();
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> s[i][j];
    }
  }
  vector<int> first;
  vector<int> second;
  cout << go(0, first, second) << '\n';
  return 0;
}