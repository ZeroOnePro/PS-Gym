import { fs, lodash } from "./index";

export const categorize = (
  cppFiles: {
    [x: string]: number;
  }[]
) =>
  lodash.reduce(
    cppFiles,
    (result: { [x: number]: string }, value, key) => {
      const swapKey = lodash.values(value)[0];
      const swapValue = lodash.keys(value)[0];
      if (!isNaN(swapKey)) result[swapKey] = swapValue;
      return result;
    },
    {}
  );
