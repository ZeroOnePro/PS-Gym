import { getFiles, getProblems, processFile } from "./data";
import { generateMarkdown } from "./markdown";

const generate = async () => {
  const cppFiles = await getFiles();
  const [problemNums, categories] = processFile(cppFiles);
  const problems = await getProblems(problemNums);
  generateMarkdown(problems, categories);
};

generate();
