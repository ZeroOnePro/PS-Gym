#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  vector<pair<int, int>> score;

  score.push_back(make_pair(0, 1));
  score.push_back(make_pair(0, 2));
  score.push_back(make_pair(0, 3));

  vector<int> one{1, 2, 3, 4, 5};
  vector<int> two{2, 1, 2, 3, 2, 4, 2, 5};
  vector<int> three{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  for (int i = 0; i < answers.size(); ++i) {
    if (one[i % 5] == answers[i]) {
      score[0].first += 1;
    }
    if (two[i % 8] == answers[i]) {
      score[1].first += 1;
    }
    if (three[i % 10] == answers[i]) {
      score[2].first += 1;
    }
  }
  sort(score.begin(), score.end());
  int max = score[2].first;
  for (int i = 0; i < 3; ++i) {
    if (max == score[i].first) {
      answer.push_back(score[i].second);
    }
  }
  return answer;
}