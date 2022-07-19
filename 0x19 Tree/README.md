# 0x19 트리

<!--ts-->

- [0x19 트리](#0x19-트리)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 BFS, DFS](#0x01-bfs-dfs)
  - [0x02 이진 트리의 순회](#0x02-이진-트리의-순회)
  - [0x03 연습 문제](#0x03-연습-문제)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 19일 화요일 13시 05분 34초 KST -->

<!--te-->

## 0x00 정의와 성질

- 정점과 간선으로 이루어진 자료구조인 그래프의 특별한 형태
- 무방향이면서 사이클이 없는 연결 그래프(undirected acyclic connected graph)
- 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프
- `임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)가 유일한 그래프`
- V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프
- 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프
- `V개의 정점을 가지고 V-1개의 간선을 가지는 Acyclic(사이클이 없는) 그래프`
- 정점이 한 개이면서 간선이 없는 그래프도 트리이다
- 아무 정점이나 루트가 될 수 있다

## 0x01 BFS, DFS

- 트리도 그래프의 일종이기에 그래프 탐색 알고리즘을 이용하여 탐색할 수 있다
- BFS

  - 임의의 시작점을 잡고 BFS를 돌리면 그 시작점을 루트로 정해서 트리를 재배치했을 때의 높이 순으로 방문한다

    ![1](https://user-images.githubusercontent.com/48282185/179662440-3a9a13ca-2c0c-4723-9bbd-284c0f97f69a.png)

    - 방문 순서: 1 → 2 → 3 → 4 → 5 → 6 → 7 →8
    - 같은 depth에서는 어떤 노드를 먼저 넣느냐에 따라 순서가 바뀔 수 있다

  - 특이점은 각 정점을 방문할 때 부모를 제외한 자식 정점들이 큐에 들어간다는 것이다 이런 특성으로 인해 어떤 노드에서 어떤 것을 방문했는지 명확히 알 수 있다 즉, 방문 여부를 체크하는 배열을 사용해도 되긴 하지만 각 노드에서 부모 정보만 가지고 있으면 인접 노드 중 어떤 노드를 방문했는지 알 수 있기에 결론적으로 한 노드을 탐색하는 시점에서 그 노드의 부모만 알고있으면 된다
    - 각 노드의 부모 정보를 필요로 하는 문제에서 유용하게 쓰일 수 있다
    - 각 노드가 몇 번 depth에 위치해 있는지도 쉽게 파악 가능 → 부모 depth + 1 = 자식 depth
    - visited 배열을 쓴 것과 코드도 크게 다르지 않다

- DFS

  - 임의의 시작점을 잡고 DFS를 돌리면 그 시작점을 루트로 정해서 트리를 재배치했을 때를 가정하는게 편하다

    ![2](https://user-images.githubusercontent.com/48282185/179662439-fc106df1-9bfd-4f1f-88ef-2efcbe5f5ba4.png)

    - 방문 순서: 1 → 2 → 5 → 3 → 4 → 6 → 7 → 8
    - BFS와 마찬가지로 부모 정보를 담고있는 배열만 있으면 된다
    - 재귀로 구현할 시 만약 스택 메모리가 1MB로 제한되어있다면 V가 대략 3만 이상일 때 메모리 초과 주의

## 0x02 이진 트리의 순회

- 지금까지 익힌 순회방식으로는 BFS와 DFS 밖에 없었지만 이진 트리에서는 특별한 순회들이 존재한다
  - 레벨 , 전위, 중위, 후위 순회
- 이진 트리도 그래프라 인접 리스트를 통해서 표현할 수 있지만, 그러면 왼쪽 자식과 오른쪽 자식을 구분 못하게 되어 특별한 형태의 자료 구조를 이용한다

  ![3](https://user-images.githubusercontent.com/48282185/179662438-48e98a9d-3283-4768-97b5-244981877dfd.png)

  - parent는 순회할 때는 필요없으나 필요한 경우 만들면 됨
  - 원소가 0이면 없다는 뜻

- 레벨 순회(Level-order Traversal)

  - BFS에 루트를 넣어주면 레벨(높이)순으로 방문하기에 루트만 넣고 BFS를 돌리면 끝

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
  int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

  void bfs(void) {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      cout << cur << ' ';
      if (lc[cur]) q.push(lc[cur]);
      if (rc[cur]) q.push(rc[cur]);
    }
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bfs(); // 1 2 3 4 5 6 7 8
    return 0;
  }
  ```

- 전위, 중위, 후위 순회 모두 재귀로 구현

- 여기서 위는 현재 가리키는 노드가 언제 방문되는가? 임
- 전위 순회(Preorder Traversal)

  1. 현재 정점을 방문한다
  2. 왼쪽 서브 트리를 전위 순회한다
  3. 오른쪽 서브 트리를 전위 순회한다

     ![4](https://user-images.githubusercontent.com/48282185/179662434-f904551c-f5d7-40a6-a9b2-815028b2f1d4.png)

  - DFS와 방문 순서가 동일

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
  int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

  void preorder_traversal(int cur) {
    cout << cur << ' ';
    if (lc[cur] != 0) preorder_traversal(lc[cur]);
    if (rc[cur] != 0) preorder_traversal(rc[cur]);
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preorder_traversal(1); // 1 2 4 5 8 3 6 7
    return 0;
  }
  ```

- 중위 순회(inorder traversal)

  - 트리가 이진 탐색 트리라면 크기 순으로 방문하는 순서
    ![5](https://user-images.githubusercontent.com/48282185/179662432-3009453b-14d8-4320-b74a-c99ee4fdaadb.png)

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
  int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

  void inorder_traversal(int cur) {
    if (lc[cur] != 0) inorder_traversal(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) inorder_traversal(rc[cur]);
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inorder_traversal(1); // 4 2 5 8 1 6 3 7
    return 0;
  }
  ```

- 후위 순회(postorder traversal)
  ![6](https://user-images.githubusercontent.com/48282185/179662419-1d8f9f43-21b0-4477-8f99-3dd33948d484.png)

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
  int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

  void postorder_traversal(int cur) {
    if (lc[cur] != 0) postorder_traversal(lc[cur]);
    if (rc[cur] != 0) postorder_traversal(rc[cur]);
    cout << cur << ' ';
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    postorder_traversal(1); // 4 8 5 2 6 7 3 1
    return 0;
  }
  ```

## 0x03 연습 문제

- 11726 - 트리의 부모 찾기
  - bfs돌면 끝
- 1991 - 트리 순회
  - preorder, inorder, postorder 잘 이해했는가?
  - 재귀함수마다 stdout하면 오래걸리니 문자열로 처리했음
- 재귀적인 처리를 통해 트리에서 DP를 하는 알고리즘이 있는데 해보자

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
