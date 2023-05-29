#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;
  queue<char> q;
  for (char ch : skill) {
    q.push(ch);
  }
  bool flag = true;
  for (string trees : skill_trees) {
    for (char ch : trees) {
      if (skill.find(ch) != -1) {
        // skill내에 있는 문자를 만난경우, 큐의 탑과 같으면 pop시키고 아니면
        // 플래그를 설정
        if (ch == q.front())
          q.pop();
        else {
          flag = false;
        }
      }
    }
    if (flag) answer += 1;
    // 스킬트리 가능 문자열이 바뀌므로
    flag = true;
    while (!q.empty()) q.pop();  // 큐 비우고
    for (char ch : skill) {      // 다시채워야지
      q.push(ch);
    }
  }
  return answer;
}