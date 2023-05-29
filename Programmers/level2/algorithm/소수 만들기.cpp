#include <iostream>
#include <vector>
using namespace std;

vector<bool> check(50000, false);

void Primes(int n) {
  // 0,1 예외 처리
  check[0] = check[1] = true;
  // i*i ~ n까지는 그 전 단계에서 걸러짐
  for (int i = 2; i <= n; ++i) {
    if (!check[i]) {
      // i*i는 오버플로우 우려때문에 2*i로 하는게 안전
      for (int j = 2 * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
}

int solution(vector<int> nums) {
  int answer = 0;
  // combination하면 50!이라 시간초과날 듯 for문이 더 빠르겟다
  Primes(50000);
  for (int i = 0; i < nums.size() - 2; ++i) {
    for (int j = i + 1; j < nums.size() - 1; ++j) {
      for (int k = j + 1; k < nums.size(); ++k) {
        if (!check[nums[i] + nums[j] + nums[k]]) answer += 1;
      }
    }
  }
  return answer;
}