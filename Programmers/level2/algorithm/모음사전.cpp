#include <bits/stdc++.h>

using namespace std;

set<string> w;

void make_word(int cur, string tmp) {
  if (cur == 5) {
    if (tmp != "") w.insert(tmp);
    return;
  }
  for (char ch : {'A', 'E', 'I', 'O', 'U'}) {
    make_word(cur + 1, tmp);
    make_word(cur + 1, tmp + ch);
  }
}

int solution(string word) {
  int answer = 0;
  make_word(0, "");
  auto it = w.find(word);
  answer = distance(w.begin(), it) + 1;
  return answer;
}