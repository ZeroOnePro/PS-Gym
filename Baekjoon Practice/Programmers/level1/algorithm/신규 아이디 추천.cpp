#include <algorithm>
#include <regex>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
  // 1단계
  transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
  // 2단계
  new_id = regex_replace(new_id, regex("[^a-z0-9-_.]+"), "");
  // 3단계
  new_id = regex_replace(new_id, regex("\\.{2,}"), ".");
  // 4단계
  if (new_id.front() == '.') new_id.erase(new_id.begin());
  if (new_id.back() == '.') new_id.pop_back();
  // 5단계
  if (new_id.empty()) new_id = "a";
  // 6단계
  if (new_id.size() >= 16) {
    new_id.erase(new_id.begin() + 15, new_id.end());
    if (new_id.back() == '.') new_id.pop_back();
  }
  // 7단계
  while (new_id.size() < 3) {
    new_id += new_id.back();
  }
  return new_id;
}