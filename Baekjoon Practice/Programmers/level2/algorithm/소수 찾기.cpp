#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 문자열에서 나올 수 있는 모든 부분순열에 대해 소수인지 검사해야함
// 138 -> 1, 3, 8, 13, 18, 31, 38, 81, 83, ...
// 001 -> 8
// 010 -> 3
// 100 -> 1
// 110 -> 13 -> 13, 31
// 101 -> 18 -> 18, 81
// 011 -> 38 -> 38, 83
// 111 -> 138 -> 두자리 부터 각 순열을 해서 일일히 모두 검사

set<int> per;
vector<bool> check(9999999, false);

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

void generate_sequence(string str) {
  do {
    for (int i = 1; i <= str.size(); ++i) {
      per.insert(stoi(str.substr(0, i)));
    }
  } while (prev_permutation(str.begin(), str.end()));
}

int solution(string numbers) {
  int answer = 0;
  sort(numbers.begin(), numbers.end(), [&](char a, char b) { return a > b; });
  generate_sequence(numbers);
  Primes(stoi(numbers));
  for (int i : per) {
    if (!check[i]) {
      answer += 1;
    }
  }
  return answer;
}