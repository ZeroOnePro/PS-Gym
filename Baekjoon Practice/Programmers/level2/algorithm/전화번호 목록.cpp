#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool startWith(string s, string prefix) { return !s.rfind(prefix, 0); }

// 백만이라 이중루프돌리면 시간 초과날 확률이 높다 여기는 시간제한이 없기 때문에
// 계산을 못한다 1초 이상일 수도 있기 때문에, 이중루프 돌려봤는데 시간초과 떴다.
// 해결법이 생각 안 나서 남이 어떻게 풀었는지 봤다. 근데 사전순 정렬하니까
// 인접요소만 비교하는 풀이가 많았다. O(nlogn) i는 i번째 요소 사전순 정렬이라
// i가 i+1의 접두어라면 loop 끝내도 됨. 즉, i+2 이상부터는 신경 x i가 i+1의
// 접두어이거나 같지 않다면(등호가 빠진다면) i가 i+2의 접두어가 되거나 같을 수
// 없음

// ---------증명-----------
// i가 i+2의 접두어라고 가정하자.
// a와 b는 임의의 문자열
// i를 k, i+1를 g, i+2를 t라 하자
// 접두어라고 했으므로, t = k + a
// 사전 순 정렬이므로, t = g + b = k + a (a >= b)이 성립한다.
// g + b = k + a 이고, a = b 이면, g = k 이다.
// 따라서 g =/= k 가정에 모순이다.
// 결론적으로 인접 요소만 비교하면 된다.

bool solution(vector<string> phone_book) {
  bool answer = true;
  sort(phone_book.begin(), phone_book.end());
  for (int i = 0; i < phone_book.size() - 1; ++i) {
    answer = !startWith(phone_book[i + 1], phone_book[i]);
    if (!answer) break;
  }
  return answer;
}