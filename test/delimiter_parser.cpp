#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string origin, string delimiter) {
  vector<string> token;
  size_t pos = 0;
  while ((pos = origin.find(delimiter)) != string::npos) {
    token.push_back(origin.substr(0, pos));
    origin.erase(0, pos + delimiter.length());
  }
  token.push_back(origin);
  return token;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (string t : parse("I am iron man", " ")) {
    cout << t << '\n';
  }
  return 0;
}