import glob from "glob";
import { compact, map, uniq } from "lodash";
import path from "path";
import util from "util";

const globModule = util.promisify(glob);

const cppFiles = globModule("./**/exercise/*.cpp");

const getCppFileList = async () => {
  const files = await cppFiles;
  return uniq(
    compact(
      map(files, (filePath: string) => ({
        [filePath.split("/")[1]]: parseInt(
          path.basename(filePath, path.extname(filePath)),
          10
        ),
      }))
    )
  );
};

export default getCppFileList;
