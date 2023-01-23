# Learning About

<!--ts-->
* [Learning About](#learning-about)
   * [<a href="https://www.acmicpc.net/problem/10845" rel="nofollow">10845 - 큐</a>](#10845---큐)
      * [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어)
      * [2. 코멘트](#2-코멘트)
   * [<a href="https://www.acmicpc.net/problem/18258" rel="nofollow">18258 - 큐 2</a>](#18258---큐-2)
      * [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-1)
      * [2. 코멘트](#2-코멘트-1)
   * [<a href="https://www.acmicpc.net/problem/2164" rel="nofollow">2164 - 카드 2</a>](#2164---카드-2)
      * [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-2)
      * [2. 코멘트](#2-코멘트-2)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 11월  3일 목요일 13시 08분 07초 KST -->

<!--te-->

## [10845 - 큐](https://www.acmicpc.net/problem/10845)

### 1. 해결 핵심 아이디어

- 큐의 push, pop, size, empty, front, back 연산 구현

### 2. 코멘트

- 입력 쿼리에 따라 맞게 처리해주면 되는 거라 어려울 것 없음

## [18258 - 큐 2](https://www.acmicpc.net/problem/18258)

### 1. 해결 핵심 아이디어

- 큐의 push, pop, size, empty, front, back 연산 구현

### 2. 코멘트

- 10845번과 동일

## [2164 - 카드 2](https://www.acmicpc.net/problem/2164)

### 1. 해결 핵심 아이디어

- N번 카드가 제일 아래인 상태로 순서대로 놓여있다
- 제일 위에 있는 카드를 바닥에 버린다는 조건을 보면, 제일 처음 원소가 제일 먼저 처리되야함을 알 수 있고, 큐를 사용해야함을 추측할 수 있다

### 2. 코멘트

- 큐 사이즈가 1이 될 때까지 pop()하고 front()를 push()해주면 된다
