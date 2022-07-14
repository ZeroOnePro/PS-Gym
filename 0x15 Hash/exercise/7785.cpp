#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  unordered_set<string> peoples;
  cin >> n;
  while (n--) {
    string name, log;
    cin >> name >> log;
    if (log == "enter")
      peoples.insert(name);
    else
      peoples.erase(name);
  }
  // 이런 식으로 iterator를 사용해서 간단하게 서로 다른 자료구조 사이에 복사
  vector<string> remainders(peoples.begin(), peoples.end());
  sort(remainders.begin(), remainders.end(), greater<string>());
  for (string name : remainders) {
    cout << name << '\n';
  }
  return 0;
}