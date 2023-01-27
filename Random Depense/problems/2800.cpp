#include <bits/stdc++.h>

using namespace std;

// 괄호 제거 함수
// 조합에 있는 번호일 때만 제거를 위해 해당 괄호의 인덱스를 기억해뒀다가
// 나중에 연산식 생성할 때 해당 인덱스 제외시키기
// 검색 빠르게 시키기 위해 set 사용, hash써도 될 듯?
string remove_paren(string exp, set<int> exclu) {
  int num = 0;                     // 발견되는 괄호의 번호
  stack<tuple<char, int, int>> s;  // (괄호, 인덱스, 괄호 번호)
  string rexp = "";                // 괄호 제거된 문자열
  set<int> idx;                    // 제거할 괄호의 인덱스
  for (int i = 0; i < exp.length(); ++i) {
    char ch = exp[i];
    if (ch == '(')
      s.push({ch, i, num++});
    else if (ch == ')') {
      auto [x, y, z] = s.top();
      if (x == '(') {
        if (exclu.find(z) != exclu.end()) {
          idx.insert(y);
          idx.insert(i);
        }
        s.pop();
      }
    }
  }
  for (int i = 0; i < exp.length(); ++i) {
    if (idx.find(i) != idx.end()) continue;
    rexp += exp[i];
  }
  return rexp;
}

// 진부분집합을 만드는 함수
// 제거할 괄호쌍 조합 생성
void create_subset(string exp) {
  int n = 0;
  int arr[15];
  set<string> rexp;
  for (char ch : exp)
    if (ch == '(') n += 1;
  for (int i = 0; i < n; ++i) arr[i] = i;
  for (int i = 1; i < (1 << n); i++) {
    set<int> subset;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) subset.insert(arr[j]);
    rexp.insert(remove_paren(exp, subset));
  }
  for (string e : rexp) cout << e << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string exp;
  cin >> exp;
  create_subset(exp);
  return 0;
}