#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string A;
  string B;
  string C;
  string D;

  cin >> A >> B >> C >> D;

  A += B;
  C += D;

  int a = stoi(A);
  int c = stoi(C);

  cout << a + c << '\n';

  return 0;
}