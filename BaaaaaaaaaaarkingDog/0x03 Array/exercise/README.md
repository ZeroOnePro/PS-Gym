# Learning About

<!--ts-->

- [Learning About](#learning-about)
  - [<a href="https://www.acmicpc.net/problem/10807" rel="nofollow">10807 - 개수 세기</a>](#10807---개수-세기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어)
  - [<a href="https://www.acmicpc.net/problem/10808" rel="nofollow">10808 - 알파벳 개수</a>](#10808---알파벳-개수)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-1)
  - [<a href="https://www.acmicpc.net/problem/11328" rel="nofollow">11328 - Strfry</a>](#11328---strfry)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-2)
  - [<a href="https://www.acmicpc.net/problem/13300" rel="nofollow">13300 - 방 배정</a>](#13300---방-배정)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-3)
    - [2. 코멘트](#2-코멘트)
  - [<a href="https://www.acmicpc.net/problem/1475" rel="nofollow">1475 - 방 번호</a>](#1475---방-번호)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-4)
    - [2. 코멘트](#2-코멘트-1)
  - [<a href="https://www.acmicpc.net/problem/1919" rel="nofollow">1919 - 애너그램 만들기</a>](#1919---애너그램-만들기)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-5)
  - [<a href="https://www.acmicpc.net/problem/2577" rel="nofollow">2577 - 숫자의 개수</a>](#2577---숫자의-개수)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-6)
  - [<a href="https://www.acmicpc.net/problem/3273" rel="nofollow">3273 - 두 수의 합</a>](#3273---두-수의-합)
    - [1. 해결 핵심 아이디어](#1-해결-핵심-아이디어-7)
    - [2. 코멘트](#2-코멘트-2)
  - [정리](#정리)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 11월  3일 목요일 13시 06분 26초 KST -->

<!--te-->

## [10807 - 개수 세기](https://www.acmicpc.net/problem/10807)

### 1. 해결 핵심 아이디어

- 빈도수 배열

## [10808 - 알파벳 개수](https://www.acmicpc.net/problem/10808)

### 1. 해결 핵심 아이디어

- 빈도수 배열

## [11328 - Strfry](https://www.acmicpc.net/problem/11328)

### 1. 해결 핵심 아이디어

- 빈도수 배열

## [13300 - 방 배정](https://www.acmicpc.net/problem/13300)

### 1. 해결 핵심 아이디어

- 빈도수 배열

### 2. 코멘트

- 입력으로부터 각 학년별, 성별의 학생이 몇 명있는지 기록해둔다
- 기록해둔 학생들을 k로 나눠서 방을 배정하고, 만약 k의 배수가
  아니라면 방의 개수를 늘린다

## [1475 - 방 번호](https://www.acmicpc.net/problem/1475)

### 1. 해결 핵심 아이디어

- 빈도수 배열

### 2. 코멘트

- 해결책 1

  - 숫자가 나올 때마다 빈도수 배열에서 차감해주고, 만약 더 이용할게 없다면 세트 수를 늘린다
  - 단 6과 9의 경우 서로 스위칭이 가능하기에, 이용할 게 없어도 서로 이용할 수 있는지 확인하고, 둘 다 이용할 수 없을 때 세트 수를 늘린다

- 해결책 2

  - 위 처럼 해도 되겠지만, 처리가 까다롭다
  - 각 숫자들의 빈도수를 세고, 6이나 9가 나올 경우는 freq[6] >= freq[9]라면, 9의 빈도수를 +1하고 반대의 경우 6의 빈도수를 +1한다
  - 가장 큰 빈도수를 갖는 원소만큼 세트가 필요하니 max_element(freq.begin(), freq.end())가 답이 된다

## [1919 - 애너그램 만들기](https://www.acmicpc.net/problem/1919)

### 1. 해결 핵심 아이디어

- 빈도수 배열

## [2577 - 숫자의 개수](https://www.acmicpc.net/problem/2577)

### 1. 해결 핵심 아이디어

- 빈도수 배열

## [3273 - 두 수의 합](https://www.acmicpc.net/problem/3273)

### 1. 해결 핵심 아이디어

- 빈도수 배열

### 2. 코멘트

- 수열 a의 원소들의 빈도수를 센 다음 freq[x-$a_i$]가 0인지 아닌지 확인하면 됨
- 쉽게 떠올릴 수 있는 2중 for문 풀이는 시간 초과 났을 것임

## 정리

- 연습 문제 모두 빈도수 배열을 이용하여 푸는 것이었는데, 빈도수 링크드 리스트, 스택, 큐는 안될까? 라고 생각해 봤을 때 빈도수라는 것은 특정 원소가 몇 번 등장했는지를 보는 것이기에, 특정 원소에 바로 접근할 필요가 있음, 이러한 특징을 생각해볼 때 제일 타당한 자료 구조는 배열이다
