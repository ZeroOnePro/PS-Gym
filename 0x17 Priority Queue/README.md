# 0x17 우선순위 큐

<!--ts-->

- [0x17 우선순위 큐](#0x17-우선순위-큐)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 기능과 구현](#0x01-기능과-구현)
  - [0x02 STL priority_queue](#0x02-stl-priority_queue)
  - [0x03 연습 문제](#0x03-연습-문제)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 17일 일요일 20시 34분 17초 KST -->

<!--te-->

## 0x00 정의와 성질

- pop을 할 때 가장 먼저 들어온 원소가 나오는 대신 우선순위가 가장 높은 원소가 나오는 큐
- heap 자료구조 사용
- 원소의 추가 O(logN)
- 우선순위가 가장 높은 원소의 확인 O(1)
- 우선순위가 가장 높은 원소의 제거 O(logN)

## 0x01 기능과 구현

- heap은 최대값 혹은 최소값을 찾기 위한 목적으로 사용한다
  - 최대값을 찾기 위한 목적으로 사용되는 heap을 최대 힙, 최소값을 찾기 위한 목적으로 사용되는 heap을 최소 힙이라고 부른다
  - 최소 힙에서는 부모가 자식보다 작아야하고 최대 힙에서는 부모가 자식보다 커야한다
  - 즉 최대값과 최소값은 항상 루트에 존재
- heap의 삽입 순서는 높이가 낮은 곳부터 높이가 같은 경우 왼쪽부터 채워나간다, 이로 인해 트리의 편향이 생기지 않는다

  ![1](https://user-images.githubusercontent.com/48282185/179396231-19ef12ff-d434-478b-9796-4944dff8edea.png)

- insert
  - heap의 특성 상 균형을 유지하고, 삽입하는 데 최악의 경우 트리의 높이만큼 비교된다 → O(logN)
- fetch
  - 최소힙이면 최소값만 최대힙이면 최대값만 O(1)에 가능하고 i번째로 작은 값이나 최소힙에서 최대값을 찾는 행위는 전체 노드를 살펴봐야하기에 이런 경우가 문제에서 요구되는 경우 heap을 쓰면 안됨
- erase
  - 루트가 제거되면 가장 마지막 leaf를 루트로 올리고 서로 비교해가면서 루트가 된 노드의 제자리를 찾아준다
  - 위의 예시에서 보면 1 삭제 시, 15가 노드가 되고, 부모가 자식보다 작아야한다는 최소힙의 조건에 위배되므로 2와 15를 바꿔주고, 15와 4를 바꾸고, 15와 8을 바꿔주면 됨
  - 자리 변경은 양쪽 두 자식을 살펴본후 둘 중 작은 자식과 위치를 바꿔야 최소힙의 조건을 만족하면서 변경이 가능하다, 만약 큰 자식과 바꿨으면 큰 자식이 작은 자식의 부모가 되므로 또 조건에 위배되기때문이다
- 구현

  - 힙에 한해서는 이진 트리를 쉽게 배열로 표현할 수 있다

    ![2](https://user-images.githubusercontent.com/48282185/179396225-c355e993-3992-4f57-b668-bdca4fcd6e63.png)

  - 0번 부터 넣어도 되는데 편의상 1번부터 시작
  - push(=insert)는 heap[size+1]에 넣고, 끝(size)부터 시작해서 계속 타고 올라오면서 루트에 도달할 때까지 찾아주기
  - top은 그냥 1번 인덱스에 있는 원소 반환
  - pop(=erase)는 루트를 제일 끝 원소와 바꾼 후, 루트부터 leaf에 도달할 때까지 제자리를 찾아준다

## 0x02 STL priority_queue

- priority_queue

  - 기본적으로 최대 힙
  - 최소 힙 선언 `priority_queue<int, vector<int> greater<int>>`
  - 멤버 함수 push, pop, top이 있다

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int main(void){
    priority_queue<int> pq; // 최대 힙
    // priority_queue<int, vector<int> greater<int>>로 선언시 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
    cout << pq.top() << '\n'; // 10
    pq.pop(); // {2, 5, 9}
    cout << pq.size() << '\n'; // 3
    if(pq.empty()) cout << "PQ is empty\n";
    else cout << "PQ is not empty\n";
    pq.pop(); // {2, 5}
    cout << pq.top() << '\n'; // 5
    pq.push(5); pq.push(15); // {2, 5, 5, 15}
    cout << pq.top() << '\n'; // 15
  }
  ```

  - 그럼 set에서도 동일한 작업을 할 수 있고, 시간복잡도도 동일하고, 제공하는 기능이 더 많은데 굳이 priority_queue를 쓸 필요가 있을까?
    - 이진 검색 트리에서도 봤듯이, 느린 O(logN)이다, 동적할당이나 균형 찾는 작업이 동반되기 때문에, 반면 priority_queue는 heap자료 구조를 사용하고, 균형을 잡는 후속 작업이 없기때문에 이진 검색 트리에 비해 2 ~ 4배 정도 더 빠르고, 공간을 차지하는 정도도 차이가 많이 난다
    - 결론, priority_queue만을 이용해서 문제를 해결할 수 있는 경우에는 priority_queue를 사용하자

## 0x03 연습 문제

- 11286 - 절댓값 힙

  - 이 문제의 경우 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다는 조건 때문에 비교 함수를 직접 짜야하는데, priority_queue를 사용해서 해결해보자
  - 기존에 알고있던 custom 비교 함수는 보통 함수 형태로 전달했었는데, priority_queue는 컨테이너이다 보니 sort와는 다르게 비교 클래스를 전달해야한다

    ```cpp
    class cmp{
     public:
      bool operator() (int a, int b){
       if(abs(a) != abs(b)) return abs(a) > abs(b);
       return a > 0 && b < 0;
      }
    };
    ```

  - 비교 논리가 true일 경우 a와 b의 swap이 일어난다, 이 문제에서는 절댓값이 작을 수록 우선순위가 높으므로 부모(a)와 자식(b)을 비교해서 abs(a) > abs(b), 즉 b의 우선순위가 더 높은 경우 swap을 시킨다
  - sort에서 사용했던 비교함수는 비교 논리가 false일 때 swap이 일어난다는 점에서 차이가 있다

    ```cpp
    // false일 때 swap, 오름차순 정렬
    bool compare_function(int a, int b) { return a < b; }

    vector<int> v = {5,4,3,2,1};
    sort(v.begin(), v.end(), compare_function);

    // 출력: 1 2 3 4 5
    ```

    - 비교함수(클래스)를 쓴다고 하면 cmp(앞에 위치해야하는 원소, 뒤에 위치해야하는 원소) = true가 되게끔 논리를 작성한다
    - 그리고 항상 cmp(a,a) = false를 만족해야한다, 아니면 런타임에러남

- 1715 - 카드 정렬하기
  - 허프만 코딩(압축에 쓰이는 알고리즘)에서 이 문제와 똑같이 카드 묶음 중 제일 작은 거와 그 다음 작은거 두 개를 묶어서 새로운 묶음으로 만들고, 또 같은 작업이 반복되서 나온 최종적인 작업의 회수가 제일 작음이 증명돼있다(그리디)
  - 이 사실만 알고 있다면, 그냥 끝나는 문제임
- n개의 원소를 힙에 집어넣었다가 크기 순으로 빼는 방식으로 정렬 → 힙 정렬 → O(NlogN)
- 우선순위 큐는 특별하게 응용되는 분야가 있다기 보다 우선 순위 큐가 제공하는 최대값 최소값 빨리 찾기를 요구하는 문제에서 쓰면 된다

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
