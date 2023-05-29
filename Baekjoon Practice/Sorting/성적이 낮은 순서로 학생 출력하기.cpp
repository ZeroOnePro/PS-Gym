#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<string, int>> grade(n, make_pair("", 0));
  for (int i = 0; i < n; ++i) {
    cin >> grade[i].first >> grade[i].second;
  }
  sort(grade.begin(), grade.end(),
       [&grade](pair<string, int> a, pair<string, int> b) {
         return a.second < b.second;
       });
  for (pair<string, int> i : grade) {
    cout << i.first << ' ';
  }
  cout << '\n';
  return 0;
}