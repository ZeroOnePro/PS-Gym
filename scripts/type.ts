import { generateMarkdown } from "./markdown";
export interface DisplayName {
  language: string;
  name: string;
  short: string;
}

export interface Tag {
  key: string;
  isMeta: boolean;
  bojTagId: string;
  problemCount: number;
  displayNames: DisplayName[];
  aliases: { alias: string }[];
}

export interface ProblemData {
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

export type GetFiles = () => Promise<
  {
    [x: string]: number;
  }[]
>;

export type ProcessFile = (
  cppFiles: {
    [x: string]: number;
  }[]
) => [
  number[],
  {
    [x: number]: string;
  }
];

export type GetProblems = (problemNums: number[]) => Promise<ProblemData[]>;

export type GenerateMarkdown = (
  problems: ProblemData[],
  categories: {
    [x: number]: string;
  }
) => void;
