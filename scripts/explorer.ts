import { glob, lodash, path, util } from "./index";

const globModule = util.promisify(glob);

const cppFiles = globModule("./**/exercise/*.cpp");

const getCppFileList = async () => {
  const files = await cppFiles;
  return lodash.uniq(
    lodash.compact(
      lodash.map(files, (filePath: string) => ({
        [filePath.split("/")[1]]: parseInt(
          path.basename(filePath, path.extname(filePath)),
          10
        ),
      }))
    )
  );
};

export default getCppFileList;
