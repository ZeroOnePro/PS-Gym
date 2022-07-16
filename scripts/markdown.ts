import { colorList } from "./constant";
import { fs, lodash } from "./index";
import levelList from "./lank";
import { GenerateMarkdown, ProblemData } from "./type";

export const generateMarkdown: GenerateMarkdown = (problems, categories) => {
  let content = "# 해결한 문제리스트\n\n";

  const file = fs.readFileSync(__dirname + `/../workbook.json`, "utf8");
  const workbook: { [key: string]: number[] } = JSON.parse(file);

  lodash.map(categories, (value: string[], key: string) => {
    content += `## ${key}\n\n`;

    const workbook_problems = workbook[key.split(" ")[0]];

    content += `![100%](https://progress-bar.dev/${value.length}/?scale=${workbook_problems.length}&title=progress&width=500&color=babaca&suffix=/${workbook_problems.length})\n\n`;

    content += `[풀이 링크](../${encodeURI(key)}/exercise)\n\n`;

    const categoriezed_problems: ProblemData[] = [];

    lodash.map(problems, (problem) => {
      if (lodash.includes(value, String(problem.problemId))) {
        categoriezed_problems.push(problem);
      }
    });

    let table = `|번호|문제|난이도|태그|\n|:---:|:---:|:---:|:---:|\n`;

    lodash.map(categoriezed_problems, (problem) => {
      table += `|${problem.problemId}|[${
        problem.titleKo
      }](https://www.acmicpc.net/problem/${
        problem.problemId
      })|<span style="color:${
        colorList[levelList[problem.level].split(" ")[0]]
      }">${levelList[problem.level]}</span>|`;
      let tagNames = "";
      lodash.map(problem.tags, (tag, index: number) => {
        tagNames += `[${
          tag.displayNames[1].name
        }](https://www.acmicpc.net/problemset?sort=ac_desc&algo=${
          tag.bojTagId
        })${index + 1 !== problem.tags.length ? ", " : ""}`;
      });
      table += `${tagNames}|\n`;
    });

    content += table;
    content += "\n";
  });

  fs.writeFileSync(__dirname + `/../solved problem list/README.md`, content);

  console.log("해결한 문제리스트를 업데이트 하였습니다.");
};
