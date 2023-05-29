#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string s) {
  vector<string> tokens;
  for (int i = 1; i < s.length(); ++i) {
    char t1 = s[i - 1];
    char t2 = s[i];
    if (isalpha(t1) && isalpha(t2)) {
      string token = "";
      token += t1;
      token += t2;
      tokens.push_back(token);
    }
  }
  return tokens;
}

int jakard(string s1, string s2) {
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  vector<string> a = parse(s1), b = parse(s2);
  // 합집합, 교집합 구하기
  // 해시로 빈도수 해보자
  unordered_map<string, int> a_freq, b_freq;
  for (string s : a) a_freq[s] += 1;
  for (string s : b) b_freq[s] += 1;
  vector<string> inter, uni;
  // a - b와 intersect(a, b) 추가
  for (auto [k, v] : a_freq) {
    // 겹치는 원소, 교집합과 합집합에 집어넣기
    if (b_freq.find(k) != b_freq.end()) {
      for (int i = 0; i < min(b_freq[k], v); ++i) inter.push_back(k);
      for (int i = 0; i < max(b_freq[k], v); ++i) uni.push_back(k);
    }
    // a - b인 원소 합집합에 집어넣기
    else
      for (int i = 0; i < v; ++i) uni.push_back(k);
  }
  // b-a 추가
  for (auto [k, v] : b_freq) {
    if (a_freq.find(k) == a_freq.end()) {
      for (int i = 0; i < v; ++i) uni.push_back(k);
    }
  }
  if (inter.size() == uni.size()) return 65536;
  return inter.size() * 65536 / uni.size();
}

int solution(string str1, string str2) {
  int answer = 0;
  answer = jakard(str1, str2);
  return answer;
}