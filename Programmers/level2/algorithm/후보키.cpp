#include <bits/stdc++.h>

using namespace std;

/*
 * 부분집합 만들어서 각 요소의 조합이 유일성 최소성을 만족하는지
 * {0, 2} 조합이 후보키라면 {0, 1, 2}는 후보키가 될 수 없음 이것도 검사 해야함
 * 중복 검사는 해시로 하기
 * 컬럼 번호를 스트링으로 만들어서 현재 조합된 문자열의 마지막 문자를 제외한
 * substr이 후보키 만족하면 해당 후보키는 최소성 만족 못함
 */

/* 반례

{ {"a","1","aaa","c","ng"},
{"a","1","bbb","e","g"},
{"c","1","aaa","d","ng"},
{"d","2","bbb","d","ng"}};

결론 : 해당 테스트케이스의 답은 5입니다. 근데 5로 안나올걸..??ㅎㅎㅎ

해당문제를 구현하는 방법은 다양하지만 대부분 유일성을 만족하는 케이스 중
최소성을 만족하지 못하는 케이스를 제거하는 방법을 택했을 것이라고 생각합니다.
위의 테스트 케이스에서 유일성을 만족하는 경우는
02, 03, 04, 13, 23, 012, 013, 014, 023, 024, 034, 123, 134, 234, 0123, 0124,
0134, 0234, 1234, 01234 이와 같습니다. (EX) 02는 0번째열과 2번째열을 의미합니다.
, 012는 0번째열, 1번째열, 2번째열을 의미합니다.)

근데 02를 기준으로 find를 할경우 문제가 발생합니다. 023은 제거가 되지만 012는
제거가 안됩니다. 그래서 02로 find를 하지않고 0과 2를 개별적으로 찾아서 최소성을
만족하지 못하는 케이스를 제거하는 방법을 선택했습니다. 그래서 최소성을 만족하지
못하는 케이스를 모두 제거하면 02, 03, 04, 13, 23 다음과 같은 결론이 나옵니다.
부디, 답변이 도움이 되셨으면 좋겠네요.

*/

const int range = 10;

int seq[range];
vector<string> subset;
set<string> candidate;

bool check(string s, vector<vector<string>>& relation) {
  vector<int> col;
  set<string> key;
  for (char ch : s) col.push_back(ch - '0');
  for (int i = 0; i < relation.size(); ++i) {
    string tmp = "";
    for (int j = 0; j < col.size(); ++j) tmp += relation[i][col[j]];
    key.insert(tmp);
  }
  if (key.size() == relation.size()) {
    candidate.insert(s);
    return true;
  }
  return false;
}

// 조합 만들면서 백트래킹 하기
void all_case(int cur, int prev, int n) {
  if (cur == n) {
    string tmp = "";
    for (int i = 0; i < cur; ++i) tmp += to_string(seq[i]);
    subset.push_back(tmp);
    return;
  }
  if (cur < n) {
    string tmp = "";
    for (int i = 0; i < cur; ++i) tmp += to_string(seq[i]);
    subset.push_back(tmp);
  }
  for (int i = 0; i < n; ++i) {
    if (prev >= i) continue;
    seq[cur] = i;
    all_case(cur + 1, seq[cur], n);
  }
}

// 최소성 만족 확인을 위해 모든 substr 검사
bool all_subset(string s) {
  int st = 0, en = s.length() - 1;
  while (st <= en) {
    vector<int> select(s.length());
    fill(select.begin() + en - st, select.end(), 1);
    do {
      string tmp = "";
      for (int i = 0; i < select.size(); ++i)
        if (select[i] == 1) tmp += s[i];
      if (candidate.find(tmp) != candidate.end()) return false;
    } while (next_permutation(select.begin(), select.end()));
    st += 1;
  }
  return true;
}

int solution(vector<vector<string>> relation) {
  int answer = 0;
  all_case(0, -1, relation[0].size());
  sort(subset.begin(), subset.end(), [](string a, string b) {
    if (a.length() == b.length()) return a <= b;
    return a.length() < b.length();
  });
  for (string s : subset) {
    bool is_candidate = all_subset(s);
    if (is_candidate && check(s, relation)) answer += 1;
  }
  return answer;
}