# Algorithm-Gym

<div align=center>

[![Solved.ac
 프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=tjdals1771)](https://solved.ac/tjdals1771) &nbsp; &nbsp; &nbsp; ![mazandi profile](http://mazandi.herokuapp.com/api?handle=tjdals1771&theme=dark)

</div>

## 공부 방법

- 바킹독 알고리즘 강의 커리큘럼에 맞춰서 이론 정리(강의 + 종만북(필요한 경우)) 및 연습 문제 풀기
- [각 챕터 별 디렉토리 내 README에 연습 문제들 문제 간단 요약 하기](https://github.com/Sparta-Gym/Algorithm-Gym/issues/44#issue-1283115599)
- 맞은 문제도 정답코드 확인하기
  - 더 효율적인 방법은 없었나, 문제를 푸는 다른 방법이 있나 보기
  - 신기한 발상이 있다면 정리
  - 별해의 경우 문제번호\_Another.cpp로 소스코드 파일명 따로 추가하기
- 풀이가 생각안나서 답안 본 문제나 다시 풀어보고 싶은 또는 다시 풀어보면 좋겠는 문제는 표시해놓고 챕터 연습문제 끝나면 다시 풀어보기
  - 문제번호\_X.cpp로 소스코드파일명 변경해놓기
- 부족하다고 느끼는 단원은 연습문제 이외에 따로 더 풀기

## 복습 계획

- 풀어봤던 문제들 다시 한 번씩 풀어본다.
- 특히 틀렸던 문제나 못 풀었던 문제들은 두 세번씩 풀어본다.

## 링크

[해결한 문제 리스트](./solved%20problem%20list/)

[각 챕터별 연습문제 리스트](https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md)

## 스크립트

```bash

yarn generate # 해결한 문제리스트 markdown 파일 생성

yarn clear # binary 실행 파일 재귀적 제거

yarn insert:toc # README.md 파일에 목차 삽입

yarn update:toc # README.md 파일 목차 갱신

yarn delete:backup # 목차 삽입 전 백업 파일들 삭제, update:toc의 결과물로 백업 파일들 생성

```
