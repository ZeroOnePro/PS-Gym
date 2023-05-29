#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = 0;
  vector<int> nums(11);
  for (int i : numbers) nums[i] += 1;
  for (int i = 0; i < 10; ++i) {
    if (nums[i] > 0) continue;
    answer += i;
  }
  return answer;
}