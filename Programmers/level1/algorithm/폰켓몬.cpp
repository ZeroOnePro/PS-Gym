#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  set<int> uniqs;
  // set은 default가 오름차순 정렬
  for (int num : nums) {
    uniqs.insert(num);
  }
  answer = min(nums.size() / 2, uniqs.size());
  return answer;
}