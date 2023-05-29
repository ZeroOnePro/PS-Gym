#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  stack<int> s;
  int board_size = board.size();
  int moves_size = moves.size();
  bool ok = true;
  for (int k = 0; k < moves_size; ++k) {
    bool ok = true;
    for (int i = 0; i < board_size; ++i) {
      if (board[i][moves[k] - 1] != 0 && ok) {
        if (!s.empty()) {
          if (board[i][moves[k] - 1] == s.top()) {
            s.pop();
            board[i][moves[k] - 1] = 0;
            ok = false;
            answer += 2;
            continue;
          }
        }
        s.push(board[i][moves[k] - 1]);
        board[i][moves[k] - 1] = 0;
        ok = false;
      }
    }
  }
  return answer;
}