# Learning About

<!--ts-->

- [Learning About](#learning-about)
  - [<a href="https://www.acmicpc.net/problem/11725" rel="nofollow">11725 - 트리의 부모 찾기</a>](#11725---트리의-부모-찾기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어)
    - [2. 코멘트](#2-코멘트)
  - [<a href="https://www.acmicpc.net/problem/1991" rel="nofollow">1991 - 트리 순회</a>](#1991---트리-순회)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-1)
    - [2. 코멘트](#2-코멘트-1)
  - [<a href="https://www.acmicpc.net/problem/4803" rel="nofollow">4803 - 트리</a>](#4803---트리)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-2)
    - [2. 코멘트](#2-코멘트-2)
  - [<a href="https://www.acmicpc.net/problem/15681" rel="nofollow">15681 - 트리와 쿼리</a>](#15681---트리와-쿼리)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-3)
    - [2. 코멘트](#2-코멘트-3)
  - [<a href="https://www.acmicpc.net/problem/1240" rel="nofollow">1240 - 노드사이의 거리</a>](#1240---노드사이의-거리)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-4)
    - [2. 코멘트](#2-코멘트-4)
  - [<a href="https://www.acmicpc.net/problem/22856" rel="nofollow">22856 - 트리 순회</a>](#22856---트리-순회)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-5)
    - [2. 코멘트](#2-코멘트-5)
  - [<a href="https://www.acmicpc.net/problem/1068" rel="nofollow">1068 - 트리</a>](#1068---트리)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-6)
    - [2. 코멘트](#2-코멘트-6)
  - [<a href="https://www.acmicpc.net/problem/20955" rel="nofollow">20955 - 민서의 응급 수술</a>](#20955---민서의-응급-수술)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-7)
    - [2. 코멘트](#2-코멘트-7)
  - [<a href="https://www.acmicpc.net/problem/14267" rel="nofollow">14267 - 회사 문화 1</a>](#14267---회사-문화-1)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-8)
    - [2. 코멘트](#2-코멘트-8)
  - [<a href="https://www.acmicpc.net/problem/2250" rel="nofollow">2250 - 트리의 높이와 너비</a>](#2250---트리의-높이와-너비)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-9)
    - [2. 코멘트](#2-코멘트-9)
  - [<a href="https://www.acmicpc.net/problem/2533" rel="nofollow">2533 - 사회망 서비스(SNS)</a>](#2533---사회망-서비스sns)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-10)
    - [2. 코멘트](#2-코멘트-10)
  - [<a href="https://www.acmicpc.net/problem/1967" rel="nofollow">1967 - 트리의 지름</a>](#1967---트리의-지름)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-11)
    - [2. 코멘트](#2-코멘트-11)
  - [<a href="https://www.acmicpc.net/problem/1167" rel="nofollow">1167 - 트리의 지름</a>](#1167---트리의-지름)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-12)
    - [2. 코멘트](#2-코멘트-12)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 11월 21일 월요일 10시 44분 57초 KST -->

<!--te-->

## [11725 - 트리의 부모 찾기](https://www.acmicpc.net/problem/11725)

### 1. 해결 핵심 아이디어

- 탐색할 때, 방문체크 배열대신 부모 배열사용하면 쉽게 해결가능

### 2. 코멘트

- 패스

## [1991 - 트리 순회](https://www.acmicpc.net/problem/1991)

### 1. 해결 핵심 아이디어

- 전위, 중위, 후위 순회 결과 출력해주면 끝
- 각 재귀마다 stdout하면 오래걸릴 수 있으므로 string concatnation 이용했음

### 2. 코멘트

- 패스

## [4803 - 트리](https://www.acmicpc.net/problem/4803)

### 1. 해결 핵심 아이디어

- 입력으로 주어지는 그래프가 트리인지 판단하기 위해 사이클을 체크하는 용도로 dfs를 사용하였다
- 사이클의 판단 여부는 트리는 첫 방문이 마지막 방문이어야한다, 왜냐하면 루트부터 임의의 자식으로 가는 경로는 오직 1개이기 때문이다
- 이 사실을 이용해서 인접 정점이 부모가 아니고, 다른 인접 정점을 살펴볼 때 이미 방문 전적이 있더라면 사이클인 것이다

### 2. 코멘트

- 재귀 함수에서 사이클 발견해서 return false했는데, 그 부분만 false로 리턴되는 것이지 전체 결과가 false가 되는게 아니다
- 전체 결과를 보기위해 트리인지 아닌지 판단하는 불리언 변수하나를 전역으로 선언한다음 사이클 발견하면 값을 바꿔주고 리턴시켜야한다
- 멍청한 실수를..

## [15681 - 트리와 쿼리](https://www.acmicpc.net/problem/15681)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1240 - 노드사이의 거리](https://www.acmicpc.net/problem/1240)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [22856 - 트리 순회](https://www.acmicpc.net/problem/22856)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1068 - 트리](https://www.acmicpc.net/problem/1068)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [20955 - 민서의 응급 수술](https://www.acmicpc.net/problem/20955)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [14267 - 회사 문화 1](https://www.acmicpc.net/problem/14267)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [2250 - 트리의 높이와 너비](https://www.acmicpc.net/problem/2250)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [2533 - 사회망 서비스(SNS)](https://www.acmicpc.net/problem/2533)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1967 - 트리의 지름](https://www.acmicpc.net/problem/1967)

### 1. 해결 핵심 아이디어

### 2. 코멘트

## [1167 - 트리의 지름](https://www.acmicpc.net/problem/1167)

### 1. 해결 핵심 아이디어

### 2. 코멘트
