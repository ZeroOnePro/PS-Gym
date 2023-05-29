#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
  vector<string> answer;
  sort(strings.begin(), strings.end(), [&](string a, string b) {
    if (a[n] == b[n]) {
      return a < b;
    }
    return a[n] < b[n];
  });
  answer = strings;
  return answer;
}