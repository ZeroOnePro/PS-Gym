import axios from "axios";
import fs from "fs";
import { compact, filter, flatMap, keys, map, reduce, values } from "lodash";
import getCppFileList from "./explorer";
import levelList from "./decisionRank";

interface DisplayName {
  language: string;
  name: string;
  short: string;
}

interface Tag {
  key: string;
  isMeta: boolean;
  bojTagId: string;
  problemCount: number;
  displayNames: DisplayName[];
  aliases: { alias: string }[];
}

interface ProblemData {
  problemId: number;
  titleKo: string;
  isSolvable: boolean;
  isParital: boolean;
  accepteUserCount: number;
  level: number;
  votedUserCount: number;
  isLevelLocked: number;
  averageTries: number;
  tags: Tag[];
}

const getProblemInfo = async (problemIds: string) => {
  const { data } = await axios.get("https://solved.ac/api/v3/problem/lookup", {
    headers: {
      "Content-Type": "application/json",
    },
    params: {
      problemIds,
    },
  });
  return data;
};

const colorList: { [key: string]: string } = {
  Bronze: "#AD5600",
  Silver: "#435F7A",
  Gold: "#EC9A01",
  Platinum: "#28E2A4",
  Diamond: "#00B4FC",
  Ruby: "#FF0062",
};

(async () => {
  let cppFileList = await getCppFileList();
  const files = compact(cppFileList.map((problem) => values(problem)[0]));
  const categorize = reduce(
    cppFileList,
    (result: { [x: number]: string }, value, key) => {
      const swapKey = values(value)[0];
      const swapValue = keys(value)[0];
      if (!isNaN(swapKey)) result[swapKey] = swapValue;
      return result;
    },
    {}
  );

  const problems: ProblemData[] = await getProblemInfo(files.join());

  let table = `|번호|문제|링크|난이도|카테고리|태그|\n|:---:|:---:|:---:|:---:|:---:|:---:|\n`;

  map(problems, (problem: ProblemData) => {
    table += `|${problem.problemId}|${
      problem.titleKo
    }|[링크](https://www.acmicpc.net/problem/${
      problem.problemId
    })|<span style="color:${
      colorList[levelList[problem.level].split(" ")[0]]
    }">${levelList[problem.level]}</span>|[${
      categorize[problem.problemId]
    }](./${categorize[problem.problemId].replace(/\s/gi, "%20")}/)|`;
    let tagNames = "";
    map(problem.tags, (tag: Tag, index: number) => {
      tagNames += `[${
        tag.displayNames[1].name
      }](https://www.acmicpc.net/problemset?sort=ac_desc&algo=${tag.bojTagId})${
        index + 1 !== problem.tags.length ? ", " : ""
      }`;
    });
    table += `${tagNames}|\n`;
  });

  fs.writeFileSync("problemList.md", table);
})();
