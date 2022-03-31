import { lodash } from "./index";

const lanks = {
  Bronze: [1, 2, 3, 4, 5],
  Silver: [6, 7, 8, 9, 10],
  Gold: [11, 12, 13, 14, 15],
  Platinum: [16, 17, 18, 19, 20],
  Diamond: [21, 22, 24, 24, 25],
  Rudy: [26, 27, 28, 29, 30],
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
