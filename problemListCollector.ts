import axios from "axios";
import fs from "fs";
import { filter, map } from "lodash";
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

(async () => {
  const cppFileList = await getCppFileList();
  const problems: ProblemData[] = await getProblemInfo(cppFileList.join());
  let table = `|번호|문제|링크|난이도|평균 시도 횟수|태그|\n|:---:|:---:|:---:|:---:|:---:|:---:|\n`;

  map(problems, (problem: ProblemData) => {
    table += `|${problem.problemId}|${
      problem.titleKo
    }|[링크](https://www.acmicpc.net/problem/${problem.problemId})|${
      levelList[problem.level]
    }|${problem.averageTries}|`;
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
