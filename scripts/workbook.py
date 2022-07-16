import pandas as pd
import json

chapters = ["0x{:02X}".format(i) for i in range(2, 31)]

workbook = {}

for chapter in chapters:
  url = f'https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/{chapter}.md'
  try:
    table = pd.read_html(url)
    problems = [ problem for problem in table[0]["문제"]]
    workbook[f"{chapter}"] = problems
  except Exception as e:
    print('예외 발생 사유: ', e)

with open('./scripts/workbook.json', 'w', encoding='utf-8') as file:
      json.dump(workbook, file)