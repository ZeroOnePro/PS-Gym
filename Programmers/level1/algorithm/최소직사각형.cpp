#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int select(bool mode, vector<vector<int>>& sizes) {
  // true일 때는 세로 고정, false일 때는 가로 고정
  for (int i = 0; i < sizes.size(); ++i) {
    if (sizes[i][1 - mode] > sizes[i][mode])
      swap(sizes[i][mode], sizes[i][1 - mode]);
  }
  int mx = 0;
  for (int i = 0; i < sizes.size(); ++i) {
    mx = max(mx, sizes[i][1 - mode]);
  }
  return mx;
}

int solution(vector<vector<int>> sizes) {
  int answer = 0;
  int width_mx = 0;
  int height_mx = 0;
  int mx = 0;
  for (int i = 0; i < sizes.size(); ++i) {
    width_mx = width_mx < sizes[i][0] ? sizes[i][0] : width_mx;
    height_mx = height_mx < sizes[i][1] ? sizes[i][1] : height_mx;
  }
  // 둘 중 큰 것은 고정, 왜냐면, 고정된 것으로 회전되는 것들도 커버 가능하기
  // 때문에
  mx = max(width_mx, height_mx);
  answer = select(mx == height_mx, sizes) * mx;
  return answer;
}