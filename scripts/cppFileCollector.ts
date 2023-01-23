import { glob, lodash, path, util } from "./index";

const globModule = util.promisify(glob);

const cppFiles = globModule("./BaaaaaaaaaaarkingDog/**/exercise/*.cpp");

const getCppFiles = async () => {
  const files = await cppFiles;
  return lodash.uniq(
    lodash.compact(
      lodash.map(files, (filePath: string) => ({
        [filePath.split("/")[2]]: parseInt(
          path.basename(filePath, path.extname(filePath)),
          10
        ),
      }))
    )
  );
};

const getProblemNums = (
  cppFiles: {
    [x: string]: number;
  }[]
) => lodash.compact(cppFiles.map((problem) => lodash.values(problem)[0]));

export { getCppFiles, getProblemNums };
