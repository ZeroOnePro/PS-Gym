import json
import multiprocessing as mp
import time
import pandas as pd

def scrap_problems(chapter):
  url = f'https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/{chapter}.md'
  try:
    workbook = {}
    table = pd.read_html(url)
    problems = [ problem for problem in table[0]["문제"]]
    workbook[f"{chapter}"] = problems
    return workbook
  except Exception as e:
    print('예외 발생 사유: ', e)

if __name__=='__main__':
  start_time = time.time()
  chapters = ["0x{:02X}".format(i) for i in range(2, 32)]
  pool = mp.Pool(processes=mp.cpu_count())
  chapter_problems = pool.map(scrap_problems, chapters)
  # pool이 작업을 끝낸 뒤에 join과 close를 불러줘야되는 이유
  # https://stackoverflow.com/questions/38271547/when-should-we-call-multiprocessing-pool-join
  pool.close()
  pool.join()
  print("--- %s seconds ---" % (time.time() - start_time))
  workbook = { next(iter(chapter_problem)): list(*chapter_problem.values())  for chapter_problem in chapter_problems if not chapter_problem is None }
  with open('./scripts/workbook.json', 'w', encoding='utf-8') as file:
        json.dump(workbook, file)
