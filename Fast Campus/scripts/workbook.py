from urllib import parse
from bs4 import BeautifulSoup
from collections import ChainMap
import multiprocessing as mp
import json
import requests
import glob
import os

def scrap_problems(chapter):
  url = f'https://github.com/rhs0266/FastCampus/blob/main/%EA%B0%95%EC%9D%98%20%EC%9E%90%EB%A3%8C/02-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/{parse.quote(chapter)}/README.md'
  try:
    workbook = {}
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')
    links = [(a['href'], a.parent.find_previous_sibling('td').text) for a in table.findAll("a") if a['href'].startswith("http://boj.kr/")]
    workbook[f"{chapter}"] = links
    return workbook
  except Exception as e:
    print('예외 발생 사유: ', e)

def generate_progress_bar(solved, total):
  return f"![progress bar](https://progress-bar.dev/{solved}/?scale={total}&title=progress&width=600&color=babaca&suffix=/{total})"


def cpp_file_collector(chapters):
  solved = {}
  for k, v in chapters.items():
    cpp_files = glob.glob(os.path.join(os.getcwd(), "Fast Campus", v, "*.cpp"))
    cpp_files = list(map(lambda path: path.split('/')[-1], cpp_files))
    solved[v] = cpp_files
  return solved

def generate_maindir_workbook(workbook, chapters, solved):
  with open(f"../README.md", 'w', encoding="utf-8") as file:
    file.write('## 연습문제 풀이\n')
    file.write('|챕터|진행도|링크|\n|:---:|:---:|:---:|\n')
    for k, v in workbook.items():
      file.write(f"|{chapters[k]}|{generate_progress_bar(len(solved[chapters[k]]), len(v))}|[링크](https://github.com/Sparta-Gym/PS-Gym/tree/main/Fast%20Campus/{parse.quote(chapters[k])})|\n")

def generate_subdir_workbook(workbook, chapters, solved):
  for k, v in chapters.items():
    with open(os.path.join(os.getcwd(), "Fast Campus", v, "README.md"), 'w', encoding="utf-8") as file:
        file.write('## 연습문제 리스트\n')
        file.write('|문제|번호|링크|풀이 여부|\n|:---:|:---:|:---:|:---:|\n')
        for problem in workbook[k]:
          problem_link, problem_name = problem
          problem_id = problem_link.split('/')[-1]
          checked = "O" if f"{problem_id}.cpp" in solved[chapters[k]] else "X"
          file.write(f"|{problem_name}|{problem_id}|[링크]({problem_link})|{checked}|\n")

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
  # ChainMap의 iteration 방향은 last -> first라 역순으로 저장됨
  # https://stackoverflow.com/questions/70691346/why-do-the-items-in-a-python-chainmap-reverse-order-when-converted-to-a-dictiona
  workbook = dict(sorted(ChainMap(*chapter_problems).items()))
  solved = cpp_file_collector(chapters)
  generate_maindir_workbook(workbook, chapters, solved)
  generate_subdir_workbook(workbook, chapters, solved)
 