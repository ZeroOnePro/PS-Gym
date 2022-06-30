import { lodash } from "./index";
import { getFiles, getProblems, processFile } from "./data";
import { generateMarkdown } from "./markdown";
import { ProblemData } from "./type";

const generate = async () => {
  const cppFiles = await getFiles();
  const [problemNums, categories] = processFile(cppFiles);
  const problems: ProblemData[] = [];
  if (problemNums.length > 100) {
    const digit = Math.ceil(problemNums.length / 100);
    for (let iter = 1; iter <= digit; ++iter) {
      problems.push(
        ...(await getProblems(problemNums.slice(100 * (iter - 1), 100 * iter)))
      );
    }
  } else {
    problems.push(...(await getProblems(problemNums)));
  }
  generateMarkdown(problems, categories);
};

generate();
