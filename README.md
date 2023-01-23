# PS-Gym

<div align=center>

[![Solved.ac
 프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=tjdals1771)](https://solved.ac/tjdals1771) &nbsp; &nbsp; &nbsp; ![mazandi profile](http://mazandi.herokuapp.com/api?handle=tjdals1771&theme=dark)

</div>

## 공부 방법

- [바킹독님 알고리즘 강의](https://www.youtube.com/watch?v=LcOIobH7ues&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY) 커리큘럼에 맞춰서 이론 정리(강의 + 종만북(필요한 경우)) 및 연습 문제 풀기
- [각 챕터 별로 keynote 작성해서 연습 문제들 문제 간단 요약 하기](https://github.com/Sparta-Gym/Algorithm-Gym/issues/44#issue-1283115599)
- 맞은 문제도 정답코드 확인하기
  - 더 효율적인 방법은 없었나, 문제를 푸는 다른 방법이 있나 보기
  - 신기한 발상이 있다면 정리
  - 별해의 경우 문제번호\_Another.cpp로 소스코드 파일명 따로 추가하기
- 풀이가 생각안나서 답안 본 문제나 다시 풀 필요있는 문제는 표시해놓고 나중에 n회독 때 다시 풀어보기
  - 문제번호\_X.cpp로 소스코드파일명 변경해놓기
- 2회독하면서 [류호석님의 강의](https://github.com/rhs0266/FastCampus) 들으면서 시야 넓히고 싶어서 복습 겸 알고리즘 다시 한 번 복습

## 풀이과정 정리

- keynote 작성하면서 어떻게 풀었는지 정리하기

- 다시보다가 정답하고 다른 해결책을 내면 왜 그런 생각을 했는지 기록하기

- 다시 풀 때 틀렸으면 왜 틀렸는지 기록하기

## 2회독 일정

- 문제 보고 아이디어 생각하고 키노트 확인 생각 안 나거나 틀리면 기록해놨다가 나중에 다시 풀기(생각 못하면 못 푼 것임)
- 2회독 끝나고 못 푼 문제 다시 풀어보기

|  일정  |                      단원                      | 문제 수 |
| :----: | :--------------------------------------------: | :-----: |
| 1일차  | 배열, 링크드 리스트, 스택, 큐, 덱, 스택의 활용 |   30    |
| 2일차  |                      BFS                       |   30    |
| 3일차  |                 재귀, 백트래킹                 |   30    |
| 4일차  |                      정렬                      |   17    |
| 5일차  |             다이나믹 프로그래밍 1              |   20    |
| 6일차  |             다이나믹 프로그래밍 2              |   20    |
| 7일차  |                    그리디 1                    |   17    |
| 8일차  |                    이분탐색                    |   21    |
| 9일차  |                   투 포인터                    |   11    |
| 10일차 |        해시, 이진검색트리, 우선순위 큐         |   25    |
| 11일차 |                     그래프                     |   13    |
| 12일차 |                      트리                      |   13    |
| 13일차 |             위상정렬, 최소신장트리             |   16    |
| 14일차 |               플로이드 알고리즘                |   15    |
| 15일차 |              다익스트라 알고리즘               |   14    |

## 링크

- [해결한 연습 문제 리스트](./solved%20problem%20list/)
- [바킹독님 연습문제집 링크](https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md)
- [류호석님 강의자료 링크](https://github.com/rhs0266/FastCampus)

## 스크립트

```bash

yarn generate # 해결한 문제리스트 markdown 파일 생성

yarn keynote # 단원 연습문제 키노트 템플릿 생성

yarn clear # binary 실행 파일 재귀적 제거

yarn insert:toc # README.md 파일에 목차 삽입

yarn update:toc # README.md 파일 목차 갱신

yarn delete:backup # 목차 삽입 전 백업 파일들 삭제, update:toc의 결과물로 백업 파일들 생성

```
