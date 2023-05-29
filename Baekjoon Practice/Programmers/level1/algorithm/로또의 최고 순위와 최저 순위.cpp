#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int clac_rank(int num) {
  if (num == 0) return 6;
  return abs(num - 6) + 1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;
  int correct = 0, unknown = 0;
  sort(win_nums.begin(), win_nums.end());
  for (int i : lottos) {
    if (binary_search(win_nums.begin(), win_nums.end(), i)) correct += 1;
    if (i == 0) unknown += 1;
  }
  int bestRank = correct + unknown, worstRank = correct;
  answer.push_back(clac_rank(bestRank));
  answer.push_back(clac_rank(worstRank));
  return answer;
}