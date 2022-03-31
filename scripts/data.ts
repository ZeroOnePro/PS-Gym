import { getProblemInfo } from "./api";
import { categorize } from "./categorize";
import { getCppFiles, getProblemNums } from "./cppFileCollector";
import { GetFiles, GetProblems, ProcessFile } from "./type";

const getFiles: GetFiles = async () => {
  const cppFiles = await getCppFiles();
  return cppFiles;
};

const processFile: ProcessFile = (cppFiles) => {
  const problemNums = getProblemNums(cppFiles);
  const categories = categorize(cppFiles);
  return [problemNums, categories];
};

const getProblems: GetProblems = async (problemNums) => {
  const problems = await getProblemInfo(problemNums.join());
  return problems;
};

export { getFiles, processFile, getProblems };
