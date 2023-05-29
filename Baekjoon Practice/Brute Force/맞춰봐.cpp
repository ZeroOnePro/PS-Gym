#include <iostream>
#include <vector>
// 경우의 수가 큰 경우 줄일 수 있는 방법과 가지치기 가능한 부분 있는지 체크
using namespace std;
vector<int> ans(10);
vector<vector<int>> sign(10, vector<int>(10));
int n;
bool check(int index) {
  int sum = 0;
  for (int i = index; i >= 0; --i) {
    sum += ans[i];
    if (sign[i][index] == 0) {
      if (sum != 0)
        return false;
    } else if (sign[i][index] < 0) {
      if (sum >= 0)
        return false;
    } else if (sign[i][index] > 0) {
      if (sum <= 0)
        return false;
    }
  }
  return true;
}

bool go(int index) {
  if (index == n) {
    return true;
  }
  if (sign[index][index] == 0) {
    ans[index] = 0;
    return check(index) && go(index + 1);
  }
  for (int i = 1; i <= 10; ++i) {
    ans[index] = sign[index][index] * i;
    if (check(index) && go(index + 1)) {
      // 반복문 내부에 잇기때문에
      // return check(index) && go(index + 1)로 하면 다른 결과 나옴
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (s[cnt] == '0') {
        sign[i][j] = 0;
      } else if (s[cnt] == '+') {
        sign[i][j] = 1;
      } else {
        sign[i][j] = -1;
      }
      cnt += 1;
    }
  }
  go(0);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}