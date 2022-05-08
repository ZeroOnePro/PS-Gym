import { lodash } from "./index";

const lanks = {
  Bronze: lodash.range(1, 6),
  Silver: lodash.range(6, 11),
  Gold: lodash.range(11, 16),
  Platinum: lodash.range(16, 21),
  Diamond: lodash.range(21, 26),
  Rudy: lodash.range(26, 31),
};

const romanLetters = ["V", "IV", "III", "II", "I"];

let levelList: { [key: number]: string } = {
  0: "Unrated",
};

let added: { [key: number]: string }[] = [];

lodash.mapKeys(lanks, (value: number[], key: string) => {
  const classify = lodash.map(value, (index: number) => {
    if (lodash.includes(value, index)) {
      return {
        [index]: `${key} ${
          romanLetters[(index % 5) - 1 === -1 ? 4 : (index % 5) - 1]
        }`,
      };
    }
  });
  added.push(...(classify as { [key: number]: string }[]));
});

levelList = lodash.merge(levelList, ...added);

export default levelList;
