#include <bits/stdc++.h>

using namespace std;

/*
중복 판매자가 있을수 있습니다. 문제 조건에서 이부분 놓쳤었네요
seller = (에밀리, 존, 스텔라, 에밀리)
amount = (2,1,1,2)

중복 판매자가 판매시마다 수수료를 소개자한테 주는 방식으로 설계해야 합니다
1번에서 에밀리가 2씩 2번을 판매했다면 판매량을 모두 더한뒤 400원에 대한 수수료
전달이 아닌 200원에 대한 수수료 한번 처리하고 그다음 에밀리 또 만났을때 또
200원에 대한 수수료 올려주는 방식으로

이유 : 만약 에밀리가 10번을 각각 1개씩 팔았다면 에밀리를 소개해준 사람은 10원씩
10번을 나누어 받을것이고 그위 소개자한테 1원씩 10번을 주게될거임 그럼 이
소개자는 자신의 위 소개자에거 0원 10번 주면됨

하지만 만약 에밀리가 10번 1개씩 팔았다고 1000원에 대한 수수료를 자신의
소개자에게 넘기면? 100원이 넘어가고 그위 소개자에게는 10원 그럼 이 소개자는
자신의 위 소개자에게 1원을 주게됨.
*/

vector<int> parent;

map<string, vector<string>> tree;
map<string, bool> vis;
map<string, vector<int>> profit;

vector<int> dfs(string cur) {
  for (string nxt : tree[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    vector<int> c_profit = dfs(nxt);
    profit[cur].insert(profit[cur].end(), c_profit.begin(), c_profit.end());
  }
  vector<int> p_profit;
  for (int& p : profit[cur]) {
    int charge = p * 0.1;
    if (charge < 1) continue;
    p_profit.push_back(charge);
    p -= charge;
  }
  return p_profit;
}

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
  vector<int> answer;
  for (int i = 0; i < referral.size(); ++i)
    tree[referral[i]].push_back(enroll[i]);
  for (int i = 0; i < seller.size(); ++i)
    profit[seller[i]].push_back(100 * amount[i]);
  dfs("-");
  for (string name : enroll) {
    int sum = 0;
    for (int p : profit[name]) sum += p;
    answer.push_back(sum);
  }
  return answer;
}