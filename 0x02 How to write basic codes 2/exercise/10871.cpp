#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> seq;
  int n, x;
  cin >> n >> x;

  while (n--)
  {
    int input;
    cin >> input;
    if (input < x)
      seq.push_back(input);
  };

  for (int elem : seq)
  {
    cout << elem << ' ';
  }
  return 0;
}