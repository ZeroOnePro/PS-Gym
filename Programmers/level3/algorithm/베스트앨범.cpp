#include <bits/stdc++.h>

using namespace std;

class compare {
 public:
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second <= b.second;
    }
    return a.first > b.first;
  }
};

typedef pair<int, int> pi2;
typedef pair<int, priority_queue<pi2, vector<pi2>, compare>> pip;

// <장르, <장르 재생횟수 합, 우선순위 큐 사이즈 2 {재생횟수, 고유 번호}>>
// 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저
// 수록합니다. => 반례

map<string, pip> album;

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  for (int i = 0; i < genres.size(); ++i) {
    if (album.find(genres[i]) != album.end()) {
      auto [play, pq] = album[genres[i]];
      play += plays[i];
      if (pq.size() >= 2) {
        if (pq.top().first < plays[i]) {
          pq.pop();
          pq.push({plays[i], i});
        }
      } else
        pq.push({plays[i], i});
      album[genres[i]] = {play, pq};
    } else {
      priority_queue<pi2, vector<pi2>, compare> pq;
      pq.push({plays[i], i});
      album[genres[i]] = {plays[i], pq};
    }
  }
  vector<pip> res;
  for (auto [name, property] : album) {
    auto [play, pq] = property;
    res.push_back({play, pq});
  }
  sort(res.begin(), res.end(), [](pip a, pip b) { return a.first > b.first; });
  for (auto [play, pq] : res) {
    stack<int> s;
    while (!pq.empty()) {
      s.push(pq.top().second);
      pq.pop();
    }
    while (!s.empty()) {
      answer.push_back(s.top());
      s.pop();
    }
  }
  return answer;
}