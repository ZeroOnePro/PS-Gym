# 0x1B 최소 신장 트리

<!--ts-->

- [0x1B 최소 신장 트리](#0x1b-최소-신장-트리)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 크루스칼 알고리즘](#0x01-크루스칼-알고리즘)
  - [0x02 프림 알고리즘](#0x02-프림-알고리즘)
  - [0x03 연습 문제](#0x03-연습-문제)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 21일 목요일 18시 01분 12초 KST -->

<!--te-->

## 0x00 정의와 성질

- 신장 트리

  - 어떤 그래프의 부분 그래프는 일부 정점과 간선만을 택해서 만들어진 그래프
  - 방향성이 없는 그래프의 부분 그래프(sub graph)들 중에서 모든 정점을 포함하는 트리
  - 그래프에서 모든 정점을 연결해야하는 문제

    ![1](https://user-images.githubusercontent.com/48282185/180174658-9991f010-82bf-4c90-8767-19005521186f.png)

  - 트리의 성질
    - 정점이 V개일 때, 간선은 V-1개
  - 그래프가 연결 그래프일 때만 신장 트리가 존재함(모든 정점을 포함해야하므로)

- 최소 신장 트리
  - 그래프의 신장 트리 중 선택된 간선의 가중치 합이 최소인 트리
  - 한 그래프의 최소 신장 트리는 여러개일 수 있다
  - 그래프의 모든 정점을 최소의 비용으로 연결하는 문제

## 0x01 크루스칼 알고리즘

- 최소 신장 트리를 구하는 알고리즘
- Union Find를 이용하여 효율적으로 구현할 수 있다(선택되는 간선으로 인한 사이클 방지)
- 과정
  1. 간선의 크기를 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택
  2. 현재 선택한 간선이 정점 u, v를 연결하는 간선이라고 할 때 만약 u와 v가 같은 그룹이라면 아무 것도 하지 않고 넘어감, u와 v가 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소 신장 트리에 추가
  3. 최소 신장 트리에 V-1개의 간선을 추가시켰다면 과정을 종료, 그렇지 않다면 그 다음으로 비용이 작은 간선을 선택한 후 2번 과정을 반복
- 그림으로 나타낸 과정

  - 정점의 색은 그룹을 의미함

    ![2](https://user-images.githubusercontent.com/48282185/180174654-e82d7763-2afe-47b9-abbc-893b8310c8eb.png)

  - 최소 가중치를 갖는 3을 아무거나 선택
  - 초기에는 모든 정점이 서로다른 그룹
  - (1, 4) 간선을 선택하고, 1과 4는 같은 그룹이 된다

    ![3](https://user-images.githubusercontent.com/48282185/180174650-48dc0f1b-c3b9-45e2-aa3b-1f268a2a1fc5.png)

  - (1, 3) 간선 선택하고, 1과 3는 같은 그룹이 된다

    ![4](https://user-images.githubusercontent.com/48282185/180174647-532301b5-be19-4b93-9722-0c958b87c308.png)

  - 최소 비용 간선으로 (3, 4) 간선이 선택되었지만, 이미 3과 4는 같은 그룹이기에 아무것도 하지 않고 넘어간다

    ![5](https://user-images.githubusercontent.com/48282185/180174643-bfb4f647-070d-4f2b-93a6-1597eb7a4fb0.png)

  - (1, 2) 간선 선택하고, 1과 2는 같은 그룹이 된다

    ![6](https://user-images.githubusercontent.com/48282185/180174639-fb51b41d-8af0-4931-be9d-1b9d46609720.png)

  - (3, 5) 간선 선택하고, 3과 5는 같은 그룹이 된다
  - V-1개의 간선이 신장 트리에 추가되었으므로 알고리즘이 종료된다

- 크루스칼 알고리즘은 사이클을 만들어내지 않는 선에서 비용이 작은 간선부터 최소 신장 트리에 편입시키는 그리디 알고리즘
  - 이미 같은 그룹 내에 존재하는 정점들 사이의 간선이 최소 신장 트리에 포함되지 않는 이유는 사이클이 생기기 때문이다
  - 정당성 증명은 귀류법이나 매트로이드라는 수학적 개념을 이용할 수 있다
- 선택된 간선을 이루는 두 정점이 어떻게 같은 그룹에 속해있는지 파악할 수 있을까?
  - 최소 신장 트리에 편입시킨 간선을 별도로 관리하고 있다고 할 때 정점 A와 B가 같은 그룹인지 판단하려면 최소 신장 트리에 편입시킨 간선들만을 가지고 A에서 B로 갈 수 있는지, 즉 A에서 flood fill을 돌렸을 때 B를 방문하는지 확인하면 된다 O(V) 소요됨 최종적으로 이 방법으로 구현하면 크루스칼 알고리즘의 시간복잡도는 간선 정렬 O(ElogE) + 최대 E번 V개의 정점이 같은 그룹인지 판단 O(VE) → O(ElogE + VE)
  - Union Find를 이용할 경우 특정 두 정점이 같은 그룹인지 다른 그룹인지를 상수시간에 확인할 수 있다(아커만 역함수) 결론적으로 이 방법의 경우 크루스칼 알고리즘의 시간복잡도는 O(ElogE)가 된다
- 구현

  ```cpp
  int v, e;

  // (비용, 정점1, 정점2)
  tuple<int, int, int> edge[100005];

  sort(edge, edge+e);

  int cnt = 0;

  for(int i=0; i<e; ++i){
   int cost, a, b;
   tie(cost, a, b) = edge[i];
   // a와 b가 같은 그룹인지 판단
   if(!is_diff_group(a, b)) continue;
   cout << cost << ' ' << a << ' ' << b;
   cnt++;
   if(cnt = v-1) break;
  }

  ```

- 1197 - 최소 신장 트리

  ```cpp

  #include <bits/stdc++.h>

  using namespace std;

  vector<int> parent(10005, -1);
  int vertex, edge;
  tuple<int, int, int> edges[100005];

  // 경로 압축 적용
  int find(int x) {
  if (parent[x] < 0) return x;
  return parent[x] = find(parent[x]);
  }

  // union by rank 적용
  bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  // parent[u] == parent[v]의 의미는
  // u와 v가 각각 disjoint set의 루트라는 의미이다
  // parent[u]의 부모가 있었다면 find(u) = find(v) = parent[parent[u]]를 반환했을 것이기 때문(v도 마찬가지)
  // union(u, v)를 하게되면, u를 루트로 하고 u, v, u의 자식들, v의 자식들이 u의 자식이 됨(경로압축 때문)
  // 만들어진 트리는 rank가 2가되고, u에 저장된 rank를 1 감소시켜야함(rank가 음수로 담긴다)
  if (parent[u] == parent[v]) parent[u] -= 1;
  // rank는 음수
  // 높이가 더 높을 수록 값이 작다
  // 항상 높이가 더 낮은 트리를 높이가 높은 트리 밑에 넣는다
  // 높이가 더 높은 쪽을 루트로 삼는다
  // v의 rank가 더 클 경우(높이가 작은 경우) u의 집합으로 합친다
  // v가 u 밑으로 들어간다
  // 각 disjoint set의 루트만 높이가 담기고 자식들에는 부모의 번호가 담긴다
  if (parent[u] < parent[v])
  parent[v] = u;
  else
  parent[u] = v;
  return true;
  }

  int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> vertex >> edge;

  for (int i = 0; i < edge; ++i) {
  int u, v, cost;
  cin >> u >> v >> cost;
  edges[i] = {cost, u, v};
  }

  sort(edges, edges + edge);

  int mst_edge = 0, min_cost = 0;

  for (int i = 0; i < edge; ++i) {
  int u, v, cost;
  tie(cost, u, v) = edges[i];
  if (!is_diff_group(u, v)) continue;
  min_cost += cost;
  mst_edge += 1;
  if (mst_edge == vertex - 1) break;
  }

  cout << min_cost;
  return 0;
  }

  ```

## 0x02 프림 알고리즘

- 최소 신장 트리를 구하는 알고리즘
- 우선순위 큐를 가지고 구현할 수 있다
- 크루스칼에 비해 구현이 어려운 편
- 크루스칼은 제일 가중치가 작은 간선을 택하는 방법 프림은 한 정점에서 시작해 확장해 나가는 방법
- 매 순간마다 제일 적은 비용을 택하는 그리디 알고리즘
- 과정

1. 임의의 정점을 선택해 최소 신장 트리에 추가
2. 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선 중 비용이 가장 작은 것을 최소 신장 트리에 추가
3. 최소 신장 트리에 V-1개의 간선이 추가될 때 까지 2번 과정을 반복

- 그림으로 보는 과정

- 주황 노드는 최소 신장 트리에 포함된 정점
- 노란색은 각 스텝에서 최소 신장 트리에 포함될 수 있는 후보 간선

  ![7](https://user-images.githubusercontent.com/48282185/180174636-9ebc3850-32f6-471c-b95d-972c4f0d09a6.png)

- 1번 정점과 연결된 간선 중 최소 가중치를 갖는 (1, 3) or (1, 4)를 택한다 → (1, 3) 택
- 3번 정점과 (1, 3) 간선이 최소 신장 트리에 포함

  ![8](https://user-images.githubusercontent.com/48282185/180174634-6d812780-8381-4655-9f59-499c1cff95ef.png)

- 1번 정점과 3번 정점에 연결된 간선 중 최소 가중치를 갖는 (1, 4) or (3, 4)를 택한다 → (3, 4) 택
- 4번 정점과 (3, 4) 간선이 최소 신장 트리에 포함

  ![9](https://user-images.githubusercontent.com/48282185/180174626-77d3ac9a-0beb-4435-be29-fca11e30b278.png)

- 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선들 (1, 2), (3, 5), (4, 5) 중 가중치가 가장 작은 (1, 2)를 선택
  - (1, 4)가 선택되지 않는 이유는 이미 1과 4가 최소 신장 트리에 포함되었기 때문
  - 프림 알고리즘은 최소 신장 트리에 포함된 정점과 포함되지 않는 정점을 잇는 간선을 추가해나가는 알고리즘임
- 2번 정점과 (1, 2) 간선이 최소 신장 트리에 포함

  ![10](https://user-images.githubusercontent.com/48282185/180174603-4f0f4d4a-4a51-4137-b40f-db17ea39de1d.png)

- 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선들 (2, 5), (3, 5),(4, 5) 중 가중치가 작은 간선 (3, 5)를 선택
- 5번 정점과 (3, 5) 간선이 최소 신장 트리에 포함
- 최소 신장 트리의 간선이 V-1개가 되었으므로 알고리즘 종료

- 매 스텝마다 최소의 값을 뽑아내고, 최소 값 후보가 추가되기도 함 → 우선순위 큐
- 우선순위 큐를 이용한 알고리즘 과정

1. 임의의 정점을 선택해 최소 신장 트리에 추가, 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가
2. 우선순위 큐에서 비용이 가장 작은 간선을 선택
3. 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무 것도 하지 않고 넘어감, 해당 간선이 최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한다면 해당 간선과 정점 v를 최소 신장 트리에 추가 후 정점 v와 최소 신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 우선순위 큐에 추가
4. 최소 신장 트리에 V-1개의 간선이 추가될 때 까지 2, 3번 과정을 반복

- 구현

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  tuple<int, int, int> edges[] = {
      {4, 1, 2}, {3, 1, 3}, {3, 1, 4}, {3, 3, 4},
      {6, 4, 5}, {5, 3, 5}, {8, 2, 5},
  };
  int v = 5;
  // (비용, 정점)
  vector<pair<int, int>> adj[v + 1];
  for (auto edge : edges) {
    int cost, from, to;
    tie(cost, from, to) = edge;
    adj[from].push_back({cost, to});
    adj[to].push_back({cost, from});
  }
  // (비용, 정점 1, 정점 2)
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  // mst에 포함됬는지 아닌지를 나타내는 플래그 배열
  vector<bool> mst_nodes(v + 1, false);
  int start = 1;
  mst_nodes[start] = true;
  for (auto edge : adj[start])
    pq.push({edge.first, start, edge.second});
  int mst_edge = 0, min_cost = 0;
  while (mst_edge < v - 1) {
    int cost, cur, nxt;
    tie(cost, cur, nxt) = pq.top();
    pq.pop();
    if (mst_nodes[nxt]) continue;
    mst_nodes[nxt] = true;
    min_cost += cost;
    mst_edge += 1;
    for (auto edge : adj[nxt]) {
      if (!mst_nodes[edge.second]) pq.push({edge.first, nxt, edge.second});
    }
  }
  cout << min_cost << '\n';
  return 0;
}
```

- 시간 복잡도
  - 각 간선이 우선선위 큐에 최대 1번 들어가고, 1번 삭제됨 O(E), 우선순위 큐에서 삽입, 삭제는 O(logE) → O(ElogE)

## 0x03 연습 문제

- 1368 - 물대기

  - 이런 문제를 최소 신장 트리를 이용하는 문제로 대응시킬 방법이 있는지 고민해볼 수 있다
  - 최소 신장 트리 문제로 대응시키려면 그래프를 어떻게 변형시켜야 할지 적절한 그래프 모델링을 알아내야하는데 이게 어렵다
  - 특정 그래프 알고리즘이 적용될 수 있을 것 같지만 상황이 100% 맞아떨어지지 않을 때 적절하게 그래프 모델링을 하는 아이디어는 자주 등장하는 풀이기법
    - 1600 - 말이 되고픈 원숭이
    - 14442 - 벽 부수고 이동하기 2
    - 위 문제들은 다른 BFS와는 달리 상태공간을 (x, y)꼴의 2차원에서 잡는 방식으로는 해결이 안되니 벽을 부순 횟수나 말의 움직임을 사용한 횟수 등을 추가로 상태 공간에 편입시켜 거기서 BFS를 돌리는 방식이었고 다르게 말하면 주어진 2차원 그래프로부터 새로운 3차원 그래프를 모델링한 후 거기에서 BFS를 했다고 생각할 수 있다
    - 난이도가 높은 편
  - 이 문제 같은 경우는 다른 논의 물을 끌어다 쓴다는 점에서는 서로 연결되있다고 볼 수 있지만, 각 논은 스스로 우물을 팔 수도 있기 때문에 100% 적절한 상황이 아님
    - 일단 연결 그래프인지부터 확인해야함
  - 그림을 그려보자
  - 일단 내 아이디어는 어디서 시작하느냐에 따라 비용이 달라진다였음
    - 각 논을 어딘가는 파야 물을 연결해줄 수 있으니 어딘가는 물을 파야함
    - 각 논을 스스로 파는 비용을 루프로 취급, 실제 그래프에 있는 거는 아닌 관념적 간선
    - 문제의 예시에서 1에서 시작하면 5 + 6(최소 신장 트리 가중치 합) = 11
    - 2에서 시작하면 4 + 6 = 10
    - 3에서 시작하면 4 + 6 = 10
    - 4에서 시작하면 3 + 6 = 10
    - 이렇게 풀면 O(V \*ElogE)가 되고, 제한에는 안걸리는데 되게 비효율적이다
  - 이 문제를 푸는 획기적인 아이디어

    - 관념적 노드를 만들고 우물을 스스로 파는 초기값을 만든 노드로 연결해서 새로운 그래프를 만듦

      ![11](https://user-images.githubusercontent.com/48282185/180174591-6837a56b-becf-4bac-87f2-57ac473243f6.png)

- 문제에서 요구하는 게 최소 신장 트리인지 파악하는 것이 중요

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
