#include <bits/stdc++.h>

using namespace std;

// 암호 만들어 놓고, 조건 불만족 시 폐기

int l, c;
char alpha[20];
char pw[20];
vector<char> vow = {'a', 'e', 'i', 'o', 'u'};

void print() {
  for (int i = 0; i < l; ++i) cout << pw[i];
  cout << '\n';
}

bool check() {
  int vow_cnt = 0, cons_cnt = 0;
  for (int i = 0; i < l; ++i) {
    char ch = pw[i];
    if (find(vow.begin(), vow.end(), ch) != vow.end())
      vow_cnt += 1;
    else
      cons_cnt += 1;
  }
  return vow_cnt >= 1 && cons_cnt >= 2;
}

void make_pw(int cur, int st) {
  if (cur == l) {
    if (check()) print();
    return;
  }
  for (int i = st; i < c; ++i) {
    pw[cur] = alpha[i];
    make_pw(cur + 1, i + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> l >> c;
  for (int i = 0; i < c; ++i) cin >> alpha[i];
  sort(alpha, alpha + c);
  make_pw(0, 0);
  return 0;
}