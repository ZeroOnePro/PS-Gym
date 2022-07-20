import { axios, lodash, fs } from "./index";

const getImages = async (level: number) => {
  const { data } = await axios.get(
    `https://static.solved.ac/tier_small/${level}.svg`,
    {
      headers: {
        "Content-Type": "application/json",
      },
    }
  );
  return data;
};

(async () => {
  const svgs = await axios.all(
    lodash.map(lodash.range(1, 31), (level: number) => getImages(level))
  );
  await Promise.all(
    svgs.map((svg: string, index: number) =>
      fs.writeFileSync(__dirname + `/images/${index + 1}.svg`, svg)
    )
  );
})();
