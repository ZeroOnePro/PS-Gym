# 회고

## 1021 - 회전하는 큐

+ 이 문제를 처음봤을 때는 최소연산회수를 찾기 위해 타겟 넘버가 중간보다 앞쪽에 위치하는지 뒤쪽에 위치하는지를 알아야했다
+ 단순하게 생각하면 덱은 인덱스를 사용할 수 있으므로 탐색이 가능하다는 얘기다.
+ 탐색말고 뭔가 효율적인 방법이 있을까 고민해보는데 각 수의 초기 인덱스는 자기자신이고(1~N까지 채워넣으므로)
+ b연산을 하면 인덱스 + 1, c연산을 하면 인덱스 -1이 되고, 처음과 끝에 도달했을 때는 모듈라 연산을 이용하여 인덱스를 재정의한다.
+ 각 연산이 일어날 때마다 초기 인덱스에서 상대적 거리를 알 수 있으므로 이것이 덱의 중간인덱스에서 얼마나 떨어져있는가를 보려했다.
+ 하지만 전제가 틀린게 각 연산이 일어난다는 것이다.
+ 이 결론에 도달했을 때 시간제한이 2초이고, 입력 값의 크기는 50이라 탐색을해도 무방하겠다는 생각이들었고. (삽입 / 삭제는 O(1)이므로)
+ 결국 탐색으로 해결했지만, 딱히 좋은 묘수가 안 떠오른다. ㅎㅎ