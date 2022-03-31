import { colorList } from "./constant";
import { fs, lodash } from "./index";
import levelList from "./lank";
import { GenerateMarkdown } from "./type";

export const generateMarkdown: GenerateMarkdown = (problems, categories) => {
  let table = `|번호|문제|난이도|카테고리|태그|\n|:---:|:---:|:---:|:---:|:---:|\n`;

  lodash.map(problems, (problem) => {
    table += `|${problem.problemId}|[${
      problem.titleKo
    }](https://www.acmicpc.net/problem/${
      problem.problemId
    })|<span style="color:${
      colorList[levelList[problem.level].split(" ")[0]]
    }">${levelList[problem.level]}</span>|[${
      categories[problem.problemId]
    }](./${categories[problem.problemId].replace(/\s/gi, "%20")}/)|`;
    let tagNames = "";
    lodash.map(problem.tags, (tag, index: number) => {
      tagNames += `[${
        tag.displayNames[1].name
      }](https://www.acmicpc.net/problemset?sort=ac_desc&algo=${tag.bojTagId})${
        index + 1 !== problem.tags.length ? ", " : ""
      }`;
    });
    table += `${tagNames}|\n`;
  });

  fs.writeFileSync(__dirname + "/../problemList.md", table);

  console.log("해결한 문제리스트를 업데이트 하였습니다.");
};
