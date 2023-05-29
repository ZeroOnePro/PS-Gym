#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
  string answer = "";
  vector<vector<int>> phone(4, vector<int>(3, 0));
  phone = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  // 행 * 3  + 열 + 1 = 요소
  // 거리 abs(다음번호 행 - 이전번호 행) + abs(다음번호 열 - 이전번호 열)
  int Lcursor = 10, Rcursor = 12;
  for (int n : numbers) {
    if (n == 0) n = 11;
    if ((n - 1) % 3 == 0) {  // 1, 4, 7
      answer += "L";
      Lcursor = n;
    } else if ((n - 1) % 3 == 2) {  // 3, 6 ,9
      answer += "R";
      Rcursor = n;
    } else {
      // 거리 계산
      int lpr = (Lcursor - 1) / 3;  // 현재 왼손 위치 행
      int lpc = (Lcursor - 1) % 3;  // 열
      int rpr = (Rcursor - 1) / 3;  // 현재 오른손 위치 행
      int rpc = (Rcursor - 1) % 3;  // 열
      int nr = (n - 1) / 3;         // 다음 버튼 행
      int nc = (n - 1) % 3;         // 열
      int Ldist = abs(lpr - nr) + abs(lpc - nc);
      int Rdist = abs(rpr - nr) + abs(rpc - nc);
      if (Ldist < Rdist) {
        answer += "L";
        Lcursor = n;
      } else if (Ldist > Rdist) {
        answer += "R";
        Rcursor = n;
      } else {
        if (hand == "right") {
          answer += "R";
          Rcursor = n;
        } else {
          answer += "L";
          Lcursor = n;
        }
      }
    }
  }
  return answer;
}