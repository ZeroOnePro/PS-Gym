# Brute Force

## Introduce
>   `모든 것을 다해보는 알고리즘`
>   > *단, 모든 경우의 수를 다해보는 시간이 문제의 시간 제한을 넘지 않아야 한다.

## breaking problem
>   `문제를 푸는 데는 크게 3단계가 존재`   
>   >`1. 문제의 가능한 경우의 수를 계산`   
>   >   > * 직접 계산을 통해서 구해봄 순열, 조합, 뽑는다 등등 수학적 지식을 통해
>   >   > * 경우의 수를 손으로 계산 이 문제가 브루트포스가 가능한 문제인지 판별

>   >`2. 가능한 모든 방법을 다 만드는 구현방법을 구상`   
>   >   > * 하나도 빠짐 없이 만들어야 한다.   
>   >   > * 대표적으로 그냥 다 해보는 방법으로는   
>   >   > * N중 for문, permutation, recursive, bitmask => 이 중에 어떤 방법이 최선인지는 문제마다 다름

>   >`3. 작성한 알고리즘에서 방법하나하나 나올 때 마다 정답을 갱신`   
>   >   > * 문제에 나와있는 대로 답을 계산해본다.   

## Time complexity
>   `O(경우의 수 X 1가지 경우를 시도해보는데 걸리는 시간)`

## Tip for PS
>   `1. 건너뛰며 해보기 - 나올 수 있는 경우를 나열하다보면 뭔가 같은게 반복되고 공통된 특징으로 그룹핑이 가능하면, 그 그룹을 통째로 하나로 묶어서 연산`
>   > 예시)   
>   > 카잉달력 - x가 M번 마다 반복되서 튀어나옴 -> M번씩 건너뛰면서 검사   
>   > 수 이어 쓰기1 - 숫자의 자릿수가 1 ~ 9 / 10 ~ 99 / ... 의 그룹으로 그룹핑이 가능 저것을 하나로 퉁치고 자릿수 덧셈을 하면 존나빨리짐..    

