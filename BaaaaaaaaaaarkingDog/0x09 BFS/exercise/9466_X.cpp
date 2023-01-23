#include <bits/stdc++.h>

using namespace std;

// 임의의 학생 x에서 시작해 다음 학생으로 계속 이동할 때

// 1. 사이클에 포함된 학생 혹은 사이클에 포함되지 않은 학생을 재방문했을 경우
// x는 사이클에 포함되지 않은 학생이다
// 지금까지 방문한 학생들을 사이클에 포함되지 않은 학생으로 분류한다.
// => 이전 방문 노드로 알 수 있음

// 2. x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고
// y는 사이클에 포함되어 있다.
// y에서 출발해 이동하며 다시 y에 도달할 때 까지 만나는 학생들을 사이클에
// 포함된 학생으로 만들고, x에서 출발해 이동하며 y에 도달할 때 까지 만나는
// 학생들을 사이클에 포함되지 않은 학생으로 만든다
// => 현재 방문하면서 만나는 재방문 노드로 알 수 있음

// 3. x를 재방문했을 경우 x는 사이클에 포함된 학생이다 x에서 출발해 이동하며
// 다시 x에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
// => 현재 방문하면서 만나는 재방문 노드로 알 수 있음

#define MAX 100005

int n;
int term[MAX];
int state[MAX];

enum States {
  NOT_VISITED = 0,
  CYCLE_IN = -1,
};

void cycle_dfs(int node) {
  int cur = node;
  while (true) {
    state[cur] = node;
    cur = term[cur];
    // 이번 실행 때 방문에서 지나간 노드에 재방문 했을 경우 => 사이클을 만난 것
    if (state[cur] == node) {
      // 사이클 외의 노드를 만날 때까지
      while (state[cur] != CYCLE_IN) {
        // 사이클의 시작점을 사이클이라고 지정해 놓고, 다시 얘가 나올 때까지
        // 사이클로 지정
        state[cur] = CYCLE_IN;
        cur = term[cur];
      }
      return;
    }
    // 이전 실행 때 방문했던 노드에 도달했을 경우
    else if (state[cur] != 0)
      return;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    fill(state + 1, state + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> term[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (state[i] == NOT_VISITED) cycle_dfs(i);
    }
    int no_term = 0;
    for (int i = 1; i <= n; ++i) {
      if (state[i] != CYCLE_IN) no_term += 1;
    }
    cout << no_term << '\n';
  }
  return 0;
}