#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  list<string> cache;
  for (string city : cities) {
    if (cacheSize > 0) {
      for (auto& c : city) c = toupper(c);
      // cache
      bool hit = find(cache.begin(), cache.end(), city) != cache.end();
      if (hit)
        answer += 1;
      else
        answer += 5;

      if (cache.size() < cacheSize)
        cache.push_back(city);
      else {
        if (hit) {
          remove(cache.begin(), cache.end(), city);
          cache.pop_back();
          cache.push_back(city);
        } else {
          cache.pop_front();
          cache.push_back(city);
        }
      }
    } else {
      answer += 5;
    }
  }
  return answer;
}