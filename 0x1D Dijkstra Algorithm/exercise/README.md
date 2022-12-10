# Learning About

<!--ts-->

- [Learning About](#learning-about)
  - [<a href="https://www.acmicpc.net/problem/1753" rel="nofollow">1753 - 최단경로</a>](#1753---최단경로)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어)
    - [2. 코멘트](#2-코멘트)
  - [<a href="https://www.acmicpc.net/problem/11779" rel="nofollow">11779 - 최소비용 구하기 2</a>](#11779---최소비용-구하기-2)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-1)
    - [2. 코멘트](#2-코멘트-1)
  - [<a href="https://www.acmicpc.net/problem/1238" rel="nofollow">1238 - 파티</a>](#1238---파티)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-2)
    - [2. 코멘트](#2-코멘트-2)
  - [<a href="https://www.acmicpc.net/problem/1504" rel="nofollow">1504 - 특정한 최단 경로</a>](#1504---특정한-최단-경로)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-3)
    - [2. 코멘트](#2-코멘트-3)
  - [<a href="https://www.acmicpc.net/problem/1916" rel="nofollow">1916 - 최소비용 구하기</a>](#1916---최소비용-구하기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-4)
    - [2. 코멘트](#2-코멘트-4)
  - [<a href="https://www.acmicpc.net/problem/1261" rel="nofollow">1261 - 알고스팟</a>](#1261---알고스팟)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-5)
    - [2. 코멘트](#2-코멘트-5)
  - [<a href="https://www.acmicpc.net/problem/17835" rel="nofollow">17835 - 면접보는 승범이네</a>](#17835---면접보는-승범이네)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-6)
    - [2. 코멘트](#2-코멘트-6)
  - [<a href="https://www.acmicpc.net/problem/20183" rel="nofollow">20183 - 골목 대장 호석 - 효율성 2</a>](#20183---골목-대장-호석---효율성-2)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-7)
    - [2. 코멘트](#2-코멘트-7)
  - [<a href="https://www.acmicpc.net/problem/24042" rel="nofollow">24042 - 횡단보도</a>](#24042---횡단보도)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-8)
    - [2. 코멘트](#2-코멘트-8)
  - [<a href="https://www.acmicpc.net/problem/1162" rel="nofollow">1162 - 도로포장</a>](#1162---도로포장)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-9)
    - [2. 코멘트](#2-코멘트-9)
  - [<a href="https://www.acmicpc.net/problem/1854" rel="nofollow">1854 - K번째 최단경로 찾기</a>](#1854---k번째-최단경로-찾기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-10)
    - [2. 코멘트](#2-코멘트-10)
  - [<a href="https://www.acmicpc.net/problem/5719" rel="nofollow">5719 - 거의 최단 경로</a>](#5719---거의-최단-경로)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-11)
    - [2. 코멘트](#2-코멘트-11)
  - [<a href="https://www.acmicpc.net/problem/13907" rel="nofollow">13907 - 세금</a>](#13907---세금)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-12)
    - [2. 코멘트](#2-코멘트-12)
  - [<a href="https://www.acmicpc.net/problem/22870" rel="nofollow">22870 - 산책 (large)</a>](#22870---산책-large)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-13)
    - [2. 코멘트](#2-코멘트-13)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 12월 10일 토요일 09시 28분 01초 KST -->

<!--te-->

## [1753 - 최단경로](https://www.acmicpc.net/problem/1753)

### 1. 해결 핵심 아이디어

- 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구해라 => 하나의 정점에서 다른 모든 정점으로의 최단 거리를 구해라 => 다익스트라 쓸 수 있다
- 모든 간선의 가중치는 10 이하의 자연수이다 => 음수 가중치를 갖는 간선이 없다 => 다익스트라 써라

### 2. 코멘트

- 패스

## [11779 - 최소비용 구하기 2](https://www.acmicpc.net/problem/11779)

### 1. 해결 핵심 아이디어

- 다익스트라 알고리즘을 사용하여 임의의 한 점에서 다른 임의의 한 점으로 가는 최단 경로 구하는 문제
- 다익스트라 알고리즘을 수행하면서 경로 복원 테이블을 이용하여 경로 복원을 할 수 있다

### 2. 코멘트

- 패스

## [1238 - 파티](https://www.acmicpc.net/problem/1238)

### 1. 해결 핵심 아이디어

- 모든 시작점에서 x까지의 최단거리, x에서 다른 모든 정점까지의 거리가 필요해서 모든 정점 간의 최단거리를 구하는 알고리즘인 플로이드를 이용할 수도 있겠지만 정점 n의 상한이 1000이라 플로이드로는 시간 초과를 피할 수 없게된다
- 그래서 모든 정점을 시작점으로 하여 다익스트라 알고리즘을 수행하여 모든 정점까지의 최단 거리를 각각 계산해주고, 왕복 거리 중 최대값을 출력해주자
- 시간 복잡도는 우선 순위 큐를 이용한 다익스트라 알고리즘은 O(ElogE)이고 그것을 모든 정점에 대해 수행하므로 O(VElogE)이므로 통과하는데 지장이 없기 때문이다

### 2. 코멘트

- 패스

## [1504 - 특정한 최단 경로](https://www.acmicpc.net/problem/1504)

### 1. 해결 핵심 아이디어

- 어려울 줄 알았는데 의외로 해법이 간단했던 문제
- 그냥 단순하게 생각해서 min{(시작, u) + (u, v) + (v, n), (시작, v) + (v, u) + (u, n)}이 정답이다
- 간선의 가중치를 더하다가 오버플로가 날 것을 생각하지 못하고(중복해서 탈 수 있다) int로 했다가 한참을 해맸다..(쪽팔린 줄 알아라)
- 시작점을 각각 1, u, v로 하여 다익스트라 알고리즘을 수행한 후 위 식을 출력해주면 정답, 최단거리가 INF와 같거나 크면 도달 불가능

### 2. 코멘트

- 패스

## [1916 - 최소비용 구하기](https://www.acmicpc.net/problem/1916)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1261 - 알고스팟](https://www.acmicpc.net/problem/1261)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [17835 - 면접보는 승범이네](https://www.acmicpc.net/problem/17835)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [20183 - 골목 대장 호석 - 효율성 2](https://www.acmicpc.net/problem/20183)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [24042 - 횡단보도](https://www.acmicpc.net/problem/24042)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1162 - 도로포장](https://www.acmicpc.net/problem/1162)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1854 - K번째 최단경로 찾기](https://www.acmicpc.net/problem/1854)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [5719 - 거의 최단 경로](https://www.acmicpc.net/problem/5719)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [13907 - 세금](https://www.acmicpc.net/problem/13907)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [22870 - 산책 (large)](https://www.acmicpc.net/problem/22870)

### 1. 해결 핵심 아이디어

### 2. 코멘트