# 0x06 큐

<!--ts-->

- [0x06 큐](#0x06-큐)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 기능과 구현](#0x01-기능과-구현)
    - [1. 배열로 구현](#1-배열로-구현)
    - [2. STL](#2-stl)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 28일 화요일 12시 52분 41초 KST -->

<!--te-->

## 0x00 정의와 성질

- first in first out
- 원소의 추가 O(1)
- 원소의 제거 O(1)
- 제일 앞/뒤의 원소 확인 O(1)
- 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

## 0x01 기능과 구현

### 1. 배열로 구현

```cpp
int MX = 1e7
int queue[MX];
int head, tail;

void push(int x){
 queue[tail++] = x;
}

int pop(){
 head++;
}

int front(){
 return queue[head];
}

int back(){
 return queue[tail-1];
}
```

- 삭제할 때 앞 공간이 계속 버려지기때문에 공간의 낭비가 발생한다.
- 때문에 이 공간을 활용하기 위해서 원형 큐를 고려해볼 수 있다.
- 원형큐는 값을 채우려고 할 때 배열이 모두 차있어서 더 이상 공간이 없을 때, pop으로 인해 버려진 공간이 있다면, 그 공간을 다시 채우는 것이다.

### 2. STL

```cpp
#include <queue>

queue<int> q;

q.push(1);
q.pop();
q.empty();
q.front();
q.back();
```

- BFS나 Flood Fill을 할 때 자주쓰이고, 이 둘은 코딩테스트 단골유형이다

**본 자료는 바킹독님의 실전 알고리즘 강의를 바탕으로 제작되었습니다**
