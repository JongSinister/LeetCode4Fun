class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans = []
        arr1 = s1.split()
        arr2 = s2.split()
        c1 = Counter(arr1)
        c2 = Counter(arr2)
        for w in arr1:
            if (c1[w] > 1):
                continue
            if (w not in arr2):
                ans.append(w)
        for w in arr2:
            if (c2[w] > 1):
                continue
            if (w not in arr1):
                ans.append(w)
        return ans
