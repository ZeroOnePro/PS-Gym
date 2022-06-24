#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

int test[10][10];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  assert(&test[0][0] == *test);
  return 0;
}