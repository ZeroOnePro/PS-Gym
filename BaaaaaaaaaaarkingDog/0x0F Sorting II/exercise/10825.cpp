#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<tuple<string, int, int, int>> stus;
  for (int i = 0; i < n; ++i) {
    string name;
    int ko, en, math;
    cin >> name >> ko >> en >> math;
    stus.push_back({name, ko, en, math});
  }
  sort(stus.begin(), stus.end(), [](auto a, auto b) {
    auto [a_name, a_ko, a_en, a_math] = a;
    auto [b_name, b_ko, b_en, b_math] = b;
    if (a_ko == b_ko) {
      if (a_en == b_en) {
        if (a_math == b_math) return a_name < b_name;
        return a_math > b_math;
      }
      return a_en < b_en;
    }
    return a_ko > b_ko;
  });
  for (auto stu : stus) cout << get<0>(stu) << '\n';
  return 0;
}