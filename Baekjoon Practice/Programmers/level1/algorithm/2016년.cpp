#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
  string answer = "";
  vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
  vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int last_time = 0;
  for (int i = 0; i < a - 1; ++i) {  // 해당 월 미포함
    last_time += month[i];
  }
  last_time += b - 1;
  answer = days[last_time % 7];
  return answer;
}
