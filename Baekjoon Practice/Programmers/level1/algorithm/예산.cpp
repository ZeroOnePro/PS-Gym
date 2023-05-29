#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
  int answer = 0;
  sort(d.begin(), d.end());
  int sum = 0;
  for (int i = 0; i < d.size(); ++i) {
    cout << sum << '\n';
    if (sum + d[i] > budget) {
      break;
    }
    sum += d[i];
    answer += 1;
  }

  return answer;
}