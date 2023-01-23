#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  unordered_map<string, int> name_to_num;
  string num_to_name[100001];
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string name;
    cin >> name;
    name_to_num[name] = i;
    num_to_name[i] = name;
  }
  while (m--) {
    string query;
    cin >> query;
    if (isdigit(query[0]))
      cout << num_to_name[stoi(query)] << '\n';
    else
      cout << name_to_num[query] << '\n';
  }
  return 0;
}