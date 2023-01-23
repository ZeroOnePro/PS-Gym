#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<long long> building;
  long long total = 0;
  while (n--) {
    long long height;
    cin >> height;
    while (!building.empty() && building.top() <= height) building.pop();
    total += building.size();
    building.push(height);
  }
  cout << total;
  return 0;
}