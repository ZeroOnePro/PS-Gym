## 0x00 알고리즘 설명

- 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘
- 스택을 사용해서 다차원배열을 순회하는 알고리즘

## 0x01 예시

1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남긴다.
2. 스택에서 원소를 꺼내어 그 칸과 상화좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때 까지 2번을 반복

- 모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)
- BFS는 큐를 이용했는데, DFS는 스택을 이용했다. 알고리즘 구현하는 과정에 있어서 차이뿐이다.
- flood fill에 활용할 수 있다.
- 방문순서에 있어 BFS와 큰 차이가 있다.
- dfs template code

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  #define x first
  #define y second

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int board[500][500];
  bool visited[500][500];

  int n, m;

  void dfs(stack<pair<int, int>> &s) {
    while (!s.empty()) {
      pair<int, int> cursor = s.top();
      s.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = cursor.x + dx[dir];
        int ny = cursor.y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny] || board[nx][ny] != 1) continue;
        visited[nx][ny] = true;
        s.push({nx, ny});
      }
    }
    return width;
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<pair<int, int>> s;
   visited[0][0] = 1;
   s.push({0,0});

   dfs(s);

   return 0;
  }
  ```

## 0x02 BFS vs DFS

- BFS는 시작점중심으로 퍼져나간다. 이 때문에 거리 순으로 방문한다는 성질이 생긴다.
- DFS는 한 방향으로 막힐 때까지 계속 그 방향만으로 나아간다.(거리 순으로 방문한다는 성질이 사라진다.)
- 다차원 배열에서 순회하는 문제를 풀 때는 BFS만을 사용해도 크게 문제될 것 없다. 거리측정도 BFS만 가능하고 Flood Fill의 경우도 BFS, DFS 둘 중 아무거나 써도 해결할 수 있기 때문이다.
- 그래프와 트리에서 유용하게 쓰인다.

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
>
> [BaaarkingDog](https://www.youtube.com/c/BaaarkingDog)
