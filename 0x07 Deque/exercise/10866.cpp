#include <bits/stdc++.h>

using namespace std;

// eval처럼 함수 이름으로 call할 수 있나 봤더니 함수포인터와 map을 사용하는데 이
// 문제를 풀기위해 그런짓을 하는 것은 너무 오버다.
// https://stackoverflow.com/questions/19473313/how-to-call-a-function-by-its-name-stdstring-in-c

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  deque<int> dq;
  int n;
  cin >> n;
  while (n--) {
    string command;
    int element;
    cin >> command;
    if (command == "push_front") {
      cin >> element;
      dq.push_front(element);
      continue;
    } else if (command == "push_back") {
      cin >> element;
      dq.push_back(element);
      continue;
    } else if (command == "pop_back") {
      cout << (dq.empty() ? -1 : dq.back());
      if (!dq.empty()) dq.pop_back();
    } else if (command == "pop_front") {
      cout << (dq.empty() ? -1 : dq.front());
      if (!dq.empty()) dq.pop_front();
    } else if (command == "size") {
      cout << dq.size();
    } else if (command == "empty") {
      cout << (int)dq.empty();
    } else if (command == "front") {
      cout << (dq.empty() ? -1 : dq.front());
    } else if (command == "back") {
      cout << (dq.empty() ? -1 : dq.back());
    }
    cout << '\n';
  }
  return 0;
}