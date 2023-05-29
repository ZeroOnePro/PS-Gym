#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

pair<string, string> tokenizer(string log) {
  pair<string, string> result;
  stringstream ss(log);
  ss >> result.first >> result.second;
  return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;
  // 신고 당한 사람: [신고한 사람, ]
  map<string, set<string>> log;
  map<string, int> mail_list;
  vector<string> freeze;
  for (auto r : report) {
    auto [value, key] = tokenizer(r);
    log[key].insert(value);
  }
  for (auto [key, value] : log) {
    if (log[key].size() >= k) freeze.push_back(key);
  }
  // 모든 사람이 정지당하는 최악의 경우, f * log[f] = 10만이니 ㄱㅊ
  for (auto f : freeze) {
    for (auto l : log[f]) mail_list[l] += 1;
  }
  for (auto id : id_list) answer.push_back(mail_list[id]);
  return answer;
}