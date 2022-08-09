#include <bits/stdc++.h>

using namespace std;

void parser(string &origin, vector<int> &tokens) {
  stack<int> s;
  for (int i = 0; i < origin.size(); ++i) {
    if (isdigit(origin[i])) {
      s.push(origin[i] - '0');
    } else {
      int digit = 1, sum = 0;
      while (!s.empty()) {
        sum += s.top() * digit;
        digit *= 10;
        s.pop();
      }
      if (sum != 0) tokens.push_back(sum);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    vector<int> tokens;
    deque<int> dq;
    string array, command;
    bool is_reverse = false, is_error = false;
    int length = 0;
    cin >> command >> length >> array;
    parser(array, tokens);
    for (int element : tokens) {
      dq.push_back(element);
    }
    for (char c : command) {
      if (c == 'R')
        is_reverse = !is_reverse;
      else {
        if (dq.empty()) {
          is_error = true;
          break;
        }
        if (!is_reverse)
          dq.pop_front();
        else
          dq.pop_back();
      }
    }
    if (is_error)
      cout << "error\n";
    else {
      if (is_reverse) reverse(dq.begin(), dq.end());
      cout << '[';
      for (int i = 0; i < (int)dq.size(); i++) {
        cout << dq[i];
        if (i + 1 != (int)dq.size()) cout << ',';
      }
      cout << "]\n";
    }
  }
  return 0;
}