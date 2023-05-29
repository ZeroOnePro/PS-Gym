#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int cursor = 0;
  int tw = 0;
  queue<int> q;
  // 다리길이가 큐의 사이즈라고 해보면, 다리 내의 빈공간은 0으로 간주하여 무게에
  // 영향 x 다리가 올라간 트럭들의 무게 지탱가능 -> 추가 불가능 -> 기존트럭들
  // 밀기 ex) 다리길이 3 무게한계 10 [7,4,5,6] 7 0 - 1초 0 7 - 2초 4 0 - 3초 5 4
  // - 4초 0 5 - 5초 6 0 - 6초 0 6 - 7초 0 0 - 8초
  for (;;) {
    answer += 1;
    if (q.size() == bridge_length) {
      tw -= q.front();
      q.pop();
    }
    if (tw + truck_weights[cursor] <= weight) {  // 추가 가능
      if (cursor == truck_weights.size() - 1) {  // 마지막 트럭
        answer += bridge_length;
        break;
      }
      tw += truck_weights[cursor];
      q.push(truck_weights[cursor]);
      cursor += 1;
    } else {  // 추가 불능
      q.push(0);
    }
  }
  return answer;
}