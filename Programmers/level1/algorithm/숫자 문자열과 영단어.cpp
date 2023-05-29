#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;
  string answer_string = "";
  string sumNum = "";
  map<string, char> numberWords = {
      {"zero", '0'},  {"one", '1'},  {"two", '2'}, {"three", '3'},
      {"four", '4'},  {"five", '5'}, {"six", '6'}, {"seven", '7'},
      {"eight", '8'}, {"nine", '9'}};
  vector<char> numbers;
  vector<string> words;

  for (pair<string, char> p : numberWords) {
    words.push_back(p.first);
    numbers.push_back(p.second);
  }

  for (char ch : s) {
    if (find(numbers.begin(), numbers.end(), ch) != numbers.end()) {
      answer_string += ch;
    } else {
      sumNum += ch;
      if (find(words.begin(), words.end(), sumNum) != words.end()) {
        answer_string += numberWords[sumNum];
        sumNum = "";
      }
    }
  }

  answer = stoi(answer_string);
  return answer;
}