# Learning About

<!--ts-->

- [Learning About](#learning-about)
  - [<a href="https://www.acmicpc.net/problem/2750" rel="nofollow">2750 - 수 정렬하기</a>](#2750---수-정렬하기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어)
    - [2. 풀이](#2-풀이)
  - [<a href="https://www.acmicpc.net/problem/2751" rel="nofollow">2751 - 수 정렬하기 2</a>](#2751---수-정렬하기-2)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-1)
    - [2. 풀이](#2-풀이-1)
  - [<a href="https://www.acmicpc.net/problem/10989" rel="nofollow">10989 - 수 정렬하기 3</a>](#10989---수-정렬하기-3)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-2)
    - [2. 풀이](#2-풀이-2)
  - [<a href="https://www.acmicpc.net/problem/11931" rel="nofollow">11931 - 수 정렬하기 4</a>](#11931---수-정렬하기-4)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-3)
    - [2. 풀이](#2-풀이-3)
  - [<a href="https://www.acmicpc.net/problem/15688" rel="nofollow">15688 - 수 정렬하기 5</a>](#15688---수-정렬하기-5)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-4)
    - [2. 풀이](#2-풀이-4)
  - [<a href="https://www.acmicpc.net/problem/10814" rel="nofollow">10814 - 나이순 정렬</a>](#10814---나이순-정렬)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-5)
    - [2. 풀이](#2-풀이-5)
  - [<a href="https://www.acmicpc.net/problem/11650" rel="nofollow">11650 - 좌표 정렬하기</a>](#11650---좌표-정렬하기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-6)
    - [2. 풀이](#2-풀이-6)
  - [<a href="https://www.acmicpc.net/problem/11651" rel="nofollow">11651 - 좌표 정렬하기 2</a>](#11651---좌표-정렬하기-2)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-7)
    - [2. 풀이](#2-풀이-7)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 9월 17일 토요일 22시 49분 46초 KST -->

<!--te-->

## [2750 - 수 정렬하기](https://www.acmicpc.net/problem/2750)

### 1. 해결 핵심 아이디어

- n개의 수 입력받고 수 정렬하기만 하면되는 문제

### 2. 풀이

- stl 함수 sort 이용

## [2751 - 수 정렬하기 2](https://www.acmicpc.net/problem/2751)

### 1. 해결 핵심 아이디어

- n개의 수 입력받고 수 정렬하기만 하면되는 문제

### 2. 풀이

- stl 함수 sort 이용

## [10989 - 수 정렬하기 3](https://www.acmicpc.net/problem/10989)

### 1. 해결 핵심 아이디어

- 이 문제는 입력 제한이 천만이고 메모리 제한이 8MB라 입력받는 수를 모두 배열에 저장할 경우 메모리 초과가 난다
- 입력 수의 조건을 보면 만보다 작은 자연수이므로 4byte \* 10000 = 40KB이므로 빈도수 배열을 이용한 counting sort를 사용할 수 있다

### 2. 풀이

- 빈도수 배열을 처음에 지역변수로 선언해서 출력과정에서 쓰레기값때문에 출력초과났었는데, 지역변수로 선언할거면 초기화 꼭해라 아니면 전역변수로 하던가

## [11931 - 수 정렬하기 4](https://www.acmicpc.net/problem/11931)

### 1. 해결 핵심 아이디어

- 입력 크기가 최대 백만이라 O(NlogN)까지는 가능
- n개를 입력받고 내림차순 정렬 후 출력해주면 끝

### 2. 풀이

- stl 함수 sort 이용

## [15688 - 수 정렬하기 5](https://www.acmicpc.net/problem/15688)

### 1. 해결 핵심 아이디어

### 2. 풀이

## [10814 - 나이순 정렬](https://www.acmicpc.net/problem/10814)

### 1. 해결 핵심 아이디어

### 2. 풀이

## [11650 - 좌표 정렬하기](https://www.acmicpc.net/problem/11650)

### 1. 해결 핵심 아이디어

### 2. 풀이

## [11651 - 좌표 정렬하기 2](https://www.acmicpc.net/problem/11651)

### 1. 해결 핵심 아이디어

### 2. 풀이
