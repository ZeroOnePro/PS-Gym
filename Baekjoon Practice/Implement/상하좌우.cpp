#include <bits/stdc++.h>
#include <iostream>
#include <vector>

void pass() {
  __asm {
		nop
  }
}

using namespace std;

string plans;

int main() {
  int n;
  cin >> n;
  cin.ignore(); // 버퍼 비우기
  getline(cin, plans, '\n');
  int x = 1, y = 1;
  for (int i = 0; i < (int)plans.size(); ++i) {
    switch (plans[i]) {
    case 'R':
      y + 1 > n ? y = y : y += 1;
      break;
    case 'L':
      y - 1 < 1 ? y = y : y -= 1;
      break;
    case 'U':
      x - 1 < 1 ? x = x : x -= 1;
      break;
    case 'D':
      x + 1 > n ? x = x : x += 1;
      break;
    default:
      pass();
    }
  }
  cout << x << ' ' << y << '\n';
  return 0;
}