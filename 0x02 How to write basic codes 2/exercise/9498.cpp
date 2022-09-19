#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int score;
  char grade;
  cin >> score;
  int firstDigit = score / 10;
  if (firstDigit == 9 || firstDigit == 10)
    grade = 'A';
  else if (firstDigit == 8)
    grade = 'B';
  else if (firstDigit == 7)
    grade = 'C';
  else if (firstDigit == 6)
    grade = 'D';
  else
    grade = 'F';
  cout << grade;
  return 0;
}