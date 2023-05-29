#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  vector<string> binary;
  // or연산 후 이진수로 바꿔가면서 '#'인지 ' '인지 넣어주기
  for (int i = 0; i < n; ++i) {
    binary.push_back(bitset<16>(arr1[i] | arr2[i]).to_string());
  }
  for (int i = 0; i < n; ++i) {
    string tmp = "";
    for (char bit : binary[i].substr(16 - n)) {
      if (bit == '1')
        tmp += "#";
      else
        tmp += " ";
    }
    answer.push_back(tmp);
  }
  return answer;
}