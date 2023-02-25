from urllib import parse
from bs4 import BeautifulSoup
from collections import ChainMap
import multiprocessing as mp
import json
import requests

def scrap_problems(chapter):
  url = f'https://github.com/rhs0266/FastCampus/blob/main/%EA%B0%95%EC%9D%98%20%EC%9E%90%EB%A3%8C/02-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/{parse.quote(chapter)}/README.md'
  try:
    workbook = {}
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')
    links = [a['href'] for a in table.findAll("a") if a['href'].startswith("http://boj.kr/")]
    workbook[f"{chapter}"] = links
    return workbook
  except Exception as e:
    print('예외 발생 사유: ', e)

if __name__=='__main__':
  chapters = {
    "01~02-완전 탐색": "01. Brute Force", 
    "03~04-정렬": "02. Sort Application",
    "05~06-이분 탐색": "03. Binary Search",
    "07~08-두 포인터": "04. Two Pointer",
    "09~11-그래프 탐색": "05. Graph & Search",
    "12-트리": "06. Tree", 
    "13-위상정렬": "07. Topological Sort",
    "14-최단거리": "08. Shortest Path",
    "15~17-동적 프로그래밍":  "09. Dynamic Programming"
  }
  pool = mp.Pool(processes=mp.cpu_count())
  chapter_problems = pool.map(scrap_problems, chapters.keys())
  pool.close()
  pool.join()
  workbook = dict(ChainMap(*chapter_problems))
  for k, v in chapters.items():
    with open(f"../{v}/README.md", 'w', encoding="utf-8") as file:
      file.write('## 연습문제 리스트\n')
      file.write('|번호|링크|\n|:---:|:---:|\n')
      for problem in workbook[k]:
        file.write(f"|{problem.split('/')[-1]}|[링크]({problem})|\n")