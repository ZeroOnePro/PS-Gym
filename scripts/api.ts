import { axios } from "./index";

export const getProblemInfo = async (problemIds: string) => {
  const { data } = await axios.get("https://solved.ac/api/v3/problem/lookup", {
    headers: {
      "Content-Type": "application/json",
    },
    params: {
      problemIds,
    },
  });
  return data;
};
