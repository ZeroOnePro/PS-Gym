# 0x0A DFS

<!--ts-->

- [0x0A DFS](#0x0a-dfs)
  - [0x00 알고리즘 설명](#0x00-알고리즘-설명)
  - [0x01 예시](#0x01-예시)
  - [0x02 BFS vs DFS](#0x02-bfs-vs-dfs)
  - [0x03 그래프 탐색과 Cycle](#0x03-그래프-탐색과-cycle)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 28일 화요일 12시 56분 31초 KST -->

<!--te-->

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

## 0x03 그래프 탐색과 Cycle

[9466번: 텀 프로젝트](http://boj.kr/9466)

- Cycle 내의 노드인지 아닌지를 판단할 수 있는 방법을 고민해보자(단, 그래프에 방향성이 있을 경우에 해당한한다.)

  - O(N^2) 풀이법(노드의 개수 N 각각에 대해 \* 사이클에 포함된 노드의 수 N)

    - 사이클 내에 있지 않은 경우 그래프 탐색 알고리즘 수행 과정 중, 절대 자기 자신으로 돌아올 수 없다.

      ![dfs1](https://user-images.githubusercontent.com/48282185/162268940-34af03a1-95b9-4456-82fb-86e853a613da.png)

      - 위의 예시에서 노드 1(사이클 외의 노드)에서 출발하면, 절대 1로 돌아올 수 없다.

    - 사이클 내에 있는 경우 그래프 탐색 알고리즘 수행 과정 중, 다시 자기 자신으로 돌아올 수 있다.

      ![dfs2](https://user-images.githubusercontent.com/48282185/162268935-0c26183d-4376-4a88-b827-24ebc215843b.png)

      - 위의 예시에서 노드 1(사이클 내의 노드)에서 출발하면, 다시 자기 자신으로 돌아올 수 있다.

    - 구현

      ```cpp
      int arr[10005];
      int n;

      bool is_cycle(int idx){
        int cur = idx;
        for(int i=0; i<n; ++i){
        cur = arr[cur];
        if(cur == idx) return true;
        }
        return false;
      }

      int main(void){
        int t; // 테스트 케이스 개수
        cin >> t;
        while(t--){
        cin >> n;
        for(int i=1; i<=n; ++i){
          cin >> arr[i];
        }
        int ans = 0;
        for(int i=1; i<=n; ++i){
          if(!is_cycle(i) ans += 1;
        }
        cout << ans;
        }
      }
      ```

    - 구현은 쉬우나 이미 방문한 칸을 다시 방문한다는 비효율적인 문제가 있다.

  - O(N) 풀이법

    - 방문했던 노드는 다시 방문할 필요가 없다. 즉, `방문 여부`라는 정보를 이용한다.

      ![dfs3](https://user-images.githubusercontent.com/48282185/162268931-535d2334-3035-4c91-91d2-73010132bb24.png)

    - 빨간 원으로 표시된 노드에서 출발하다가 별을 만나면 최초로 만나는 재방문 노드가 자기 자신이 아니기 때문에, 빨간 원 노드는 사이클 내에 포함돼있지 않다는 것을 알 수 있다.

      ![dfs4](https://user-images.githubusercontent.com/48282185/162268924-347b3403-a127-4008-9dd3-31f521bd7fb3.png)

    - 보라 원으로 표시된 노드가 사이클 내에 포함돼있는지 알기 위해서 탐색을 진행하는데, 이미 빨간원이 사이클 외의 노드란 걸 알고 있다고 하자. 그러면 보라 원은 이 사실로 인해 사이클 외의 노드라는 것을 알 수 있다. 즉, O(N^2)풀이에서 처럼 비효율적으로 재방문할 필요가 없다.
    - 각 노드를 탐색할 때 자기 자신이 사이클 내의 노드인지 아닌지 표시하면, 위의 방법을 이용할 수 있다. 표시를 남기지 않는다면, 빨간 원이 사이클 외의 노드란 것을 모를 것이다.
    - 정리

      - 임의의 학생 x에서 시작해 다음 학생으로 계속 이동할 때 아래 세 가지 케이스가 가능하다. 1. 사이클에 포함된 학생(위의 예시 별) 혹은 사이클에 포함되지 않은 학생(위의 예시 빨간 원)을 재방문했을 경우 x(위의 예시 보라 원)는 사이클에 포함되지 않은 학생이다. 지금까지 방문한 학생들을 사이클에 포함되지 않은 학생으로 분류한다. 2. x가 아닌 다른 방문한 학생 y를 재방문했을 경우 x는 사이클에 포함되지 않고 y는 사이클에 포함되어 있다. y에서 출발해 이동하며 다시 y에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만들고, x에서 출발해 이동하며 y에 도달할 때까지 만나는 학생들을 사이클에 포함되지 않은 학생으로 만든다. 3. x를 재방문했을 경우는 x는 사이클에 포함된 학생이다. x에서 출발해 이동하며 다시 x에 도달할 때 까지 만나는 학생들을 사이클에 포함된 학생으로 만든다.
      - 각 학생을 최대 2번 방문하므로 O(2N) = O(N)
      - 위 세가지 케이스를 바탕으로 곧이곧대로 구현하면 아래와 같이 된다.

        ![dfs5](https://user-images.githubusercontent.com/48282185/162268909-d77c4257-ffac-4f90-a6ac-2dbbf6fdcdeb.png)

      - 하지만 방문 체크를 달리하여 ‘사이클에 포함되지 않은 학생’의 상태값을 달리 두지 않을 수 있는데(NOT_CYCLE_IN을 별도로 두지 않는다) 그러기 위해서는 각 탐색에서 이전에 방문한 값 y를 방문했을 때 y가 이번 탐색에서 방문된 값인지, 이전의 탐색에서 방문된 값인지를 구분할 수 있어야 한다. CYCLE_IN은 -1로 NOT_VISITED는 0으로 딱 두 가지상태만 만들고 이외의 상태는 탐색을 돌면서 탐색의 시작점 번호로 지정해 준다.
      - 이번 방문에서 지나간 노드에 도달했는지, 이전 방문에서 지나간 노드에 도달했는지만 신경을 쓰면 되어서 케이스 분류가 조금 덜 복잡해지고 코드가 간결해졌다.
      - 이와 같이 BFS를 여러 시작점에 대해서 진행해야 할 때 방문 체크 배열을 매번 새로 만들거나 초기화를 시키면 O(N^2)이 되지만 방문 여부를 체크하는 값을 매번 다른 값을 넣어 O(N)으로 만드는 테크닉(위 처럼 0과 1이 아닌)이 유용할 때가 있어서 알아두면 좋다.

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
>
> [BaaarkingDog](https://www.youtube.com/c/BaaarkingDog)
>
> [[BOJ] 9466번: 텀 프로젝트](https://www.youtube.com/watch?v=yPuow6aACvE)
