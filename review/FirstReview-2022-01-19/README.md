# 리뷰 노트

## 0x03 배열

### 1475 - 방 번호

+ 클리어

## 0x05 스택

### 1874 - 스택 수열(다시 틀림)

+ 정답 출력을 고려하지 않고, 문제를 풀어서 풀이가 잘못되었다.
+ 정답을 출력하기 위해서는 시뮬레이션을 해야함을 염두에 두자
+ 시뮬레이션 중 중간 과정이 어디까지 진행됐는지 확인하는 cursor변수를 둔다.
+ 입력되는 수열은 pop되는 순서이므로 이를 그대로 모방한다.
+ 입력 값보다 수열의 top이 크면, 입력 값이 오름차순으로 들어오지 않음을 의미한다.(즉, 스택에 내림차순으로 쌓였다.)
+ 이런 경우는 불가능한 케이스이다.

### 6198 - 옥상 정원 꾸미기(다시 틀림)

+ 탑의 위치 순서와 문제에서 풀어야할 문제가 같은 방향이다.
+ 그리고 이 문제의 특이점은 스택의 사이즈를 이용한다는 점이다.

### 3015 - 오아시스 재결합(다시 틀림)

+ 중간에 pop되면서 그 순서가 유지가 안되는게 스택에서 잘 못푸는 유형 인 것 같다.
+ 중간에 pop되는게 그 이전에 쌓였던 top을 이용한 계산에 포함되야 한다면, pair형태의 구조를 스택에 쌓는 것을 고려해보자.

### 0x05 스택 총평

+ 스택에 진짜 취약한 것 같다.
+ 중간에 pop되는 풀이가 직관적으로 이해가 잘 안 가고, 너무 중간에 pop되지 않는 풀이만을 고집하는 것 같다. 그래서 자꾸 풀이가 산으로 가는 느낌이다.
+ `틀린 문제는 제대로 복습 안 하니 다시 틀린다.`
+ [2841](https://www.acmicpc.net/problem/2841)
+ [9935](https://www.acmicpc.net/problem/9935)
+ [2800](https://www.acmicpc.net/problem/2800)
+ [17299](https://www.acmicpc.net/problem/17299)
+ [17298](https://www.acmicpc.net/problem/17298)
+ [23284](https://www.acmicpc.net/problem/23284)
+ [17608](https://www.acmicpc.net/problem/17608)

+ 추가적으로 풀어볼 문제들 백준 문제집 링크 - 스택

+ [알고리즘 분류 - 스택](https://www.acmicpc.net/problemset?sort=ac_desc&algo=71&algo_if=and&page=1)
+ [자료구조 문제집 easy](https://www.acmicpc.net/workbook/view/7750)
+ [자료구조 문제집 normal](https://www.acmicpc.net/workbook/view/7751)
+ [자료구조 문제집 hard](https://www.acmicpc.net/workbook/view/7752)