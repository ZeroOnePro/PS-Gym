#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 0;
  unordered_map<string, int> type;
  for (vector<string> clothe : clothes) type[clothe[1]] += 1;
  int combi = 1;
  for (auto [t, i] : type) combi *= (i + 1);
  answer = combi - 1;
  return answer;
}