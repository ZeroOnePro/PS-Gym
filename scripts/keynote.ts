import { getProblems } from "./data";
import { fs, readline } from "./index";
import { ProblemData } from "./type";

const readWorkbookFile = (chapter_to_hex: string) => {
  const file = fs.readFileSync(__dirname + `/workbook.json`, "utf8");
  const workbook: { [key: string]: number[] } = JSON.parse(file);
  return workbook[chapter_to_hex];
};

const readInput = async () => {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
  });

  const input: string = await new Promise((resolve) => {
    rl.question("템플릿을 생성할 단원의 헥사코드 입력 >> ", resolve);
  });

  rl.close();

  return input;
};

const generateTemplate = (problems: ProblemData[]) => {
  let template = "# Learning About\n\n";

  problems.map((problem) => {
    template += `## <a href="https://www.acmicpc.net/problem/${problem.problemId}" target="_blank">${problem.problemId} - ${problem.titleKo}</a>\n\n`;
    template += `### 1. 해결 핵심 아이디어\n\n`;
    template += `### 2. 풀이\n\n`;
  });

  return template;
};

const main = async () => {
  try {
    const input = await readInput();
    const problemNums = readWorkbookFile(input);
    const problems = await getProblems(problemNums);
    const template = generateTemplate(problems);

    const path = fs
      .readdirSync(__dirname + "/../", { withFileTypes: true })
      .filter(
        (dirent) => dirent.isDirectory() && dirent.name.startsWith(input)
      );

    const fullPath = `${path[0].name}/exercise/README.md`;

    fs.writeFileSync(__dirname + `/../${fullPath}`, template);
  } catch (error) {
    console.log(error);
  }
};

main();
