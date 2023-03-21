#include <bits/stdc++.h>

using namespace std;

int freq[10];

void load_balance(int a) {
  int b = a == 6 ? 9 : 6;
  if (freq[a] <= freq[b])
    freq[a] += 1;
  else
    freq[b] += 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string room_number;
  cin >> room_number;
  for (char ch : room_number) {
    if (ch == '6')
      load_balance(6);
    else if (ch == '9')
      load_balance(9);
    else
      freq[ch - '0'] += 1;
  }
  cout << *max_element(freq, freq + 10);
  return 0;
}