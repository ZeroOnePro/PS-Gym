#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize_getline(const string &data,
                                const char delimiter = ' ') {
  vector<string> result;
  string token;
  stringstream ss(data);

  while (getline(ss, token, delimiter)) {
    result.push_back(token);
  }
  return result;
}

bool startWith(string s, string prefix) { return !s.rfind(prefix, 0); }

// leave일 때 이름 미변경
// enter와 change 일 때 이름 저장

vector<string> solution(vector<string> record) {
  vector<string> answer, commend;
  // uuid, nickname
  map<string, string> personalRecord;
  vector<pair<string, string> > chatLogs;
  for (string s : record) {
    commend = tokenize_getline(s, ' ');
    if (commend.size() == 3) {
      personalRecord[commend[1]] = commend[2];
    }
    chatLogs.push_back({commend[0], commend[1]});
  }
  for (pair<string, string> p : chatLogs) {
    if (p.first == "Enter") {
      answer.push_back(personalRecord[p.second] + "님이 들어왔습니다.");
    } else if (p.first == "Leave") {
      answer.push_back(personalRecord[p.second] + "님이 나갔습니다.");
    } else {
      continue;
    }
  }
  return answer;
}