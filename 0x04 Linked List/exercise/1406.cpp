#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string text;
  cin >> text;
  int m;
  cin >> m;
  list<char> editor;
  for (auto ch : text) {
    editor.push_back(ch);
  }
  int init = editor.size();
  auto cursor = editor.end();
  while (m--) {
    string command;
    cin >> command;
    if (command == "L") {
      if (cursor != editor.begin()) --cursor;
    } else if (command == "D") {
      if (cursor != editor.end()) ++cursor;
    } else if (command == "B") {
      if (cursor != editor.begin()) {
        cursor--;
        cursor = editor.erase(cursor);
      }
    } else {
      char add;
      cin >> add;
      if (cursor != editor.begin()) {
        editor.insert(cursor, add);
      } else {
        editor.push_front(add);
      }
    }
  }
  for (auto i : editor) {
    cout << i;
  }
  cout << '\n';
  return 0;
}