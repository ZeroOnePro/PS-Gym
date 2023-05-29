#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer;
  map<string, int> voca;
  voca.insert({words[0], 1});
  int wrongTurn = 0;
  for (int turn = 1; turn < words.size(); ++turn) {
    if (voca.find(words[turn]) == voca.end() &&
        *(words[turn - 1].end() - 1) == *(words[turn].begin())) {
      voca.insert({words[turn], turn + 1});
    } else {
      wrongTurn = turn + 1;
      break;
    }
  }
  wrongTurn ? answer.push_back(wrongTurn % n ? (wrongTurn % n) : n)
            : answer.push_back(0);
  answer.push_back(ceil(wrongTurn / double(n)));
  return answer;
}