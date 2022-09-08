import pandas as pd
import json
import multiprocessing as mp
import time

chapters = ["0x{:02X}".format(i) for i in range(2, 32)]

workbook = {}

def get_problems(chapter):
  url = f'https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/{chapter}.md'
  try:
    table = pd.read_html(url)
    problems = [ problem for problem in table[0]["문제"]]
    workbook[f"{chapter}"] = problems
  except Exception as e:
    print('예외 발생 사유: ', e)

if __name__=='__main__':
  start_time = time.time()
  pool = mp.Pool(processes=mp.cpu_count())
  pool.map(get_problems, chapters)
  print("--- %s seconds ---" % (time.time() - start_time))

  with open('workbook.json', 'w', encoding='utf-8') as file:
        json.dump(workbook, file)
