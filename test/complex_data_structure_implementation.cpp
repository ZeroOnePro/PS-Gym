#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<string, vector<pair<char, int>>> statics;
  vector<string> grade[4];
  set<string> names;
  vector<pair<string, vector<pair<char, int>>>> test_data = {
      {"abc", {{'a', 10}, {'b', 15}, {'c', 1}, {'d', 4}}},
      {"def", {{'a', 10}, {'b', 24}, {'c', 4}, {'d', 3}}},
      {"ghi", {{'a', 18}, {'b', 3}, {'c', 2}, {'d', 2}}}};
  for (auto data : test_data) {
    string name;
    vector<pair<char, int>> grade_info;
    tie(name, grade_info) = data;
    statics[name] = grade_info;
    names.insert(name);
  }
  // map은 정렬이 안된다, 애당초에 트리라서
  // value기준으로 정렬하고 싶을 때는 vector로 옮겨서 작업해야함
  for (string s : names) {
    sort(statics[s].begin(), statics[s].end(),
         [](pair<char, int> a, pair<char, int> b) {
           return a.second > b.second;
         });
  }

  for (auto data : statics) {
    grade[data.second[0].first - 'a'].push_back(data.first);
  }

  for (int i = 0; i < 4; ++i) {
    if (grade[i].size() >= 2) {
      sort(grade[i].begin(), grade[i].end(), [&](string a, string b) {
        int index = 1;
        while (statics[a][index].first == statics[b][index].first) {
          index += 1;
        }
        return statics[a][index].first < statics[b][index].first;
      });
    }
  }

  for (int i = 0; i < 4; ++i) {
    cout << char('a' + i) << ": ";
    for (string s : grade[i]) cout << s << ' ';
    cout << '\n';
  }
  return 0;
}