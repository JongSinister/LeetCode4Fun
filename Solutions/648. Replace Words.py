class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        arr = sentence.strip().split()
        dictionary.sort()
        ans = ""
        for i in range(len(arr)):
            check = True
            for word in dictionary:
                if (arr[i][:len(word)] == word):
                    check = False
                    ans += word+" "
                    break
            if (check):
                ans += arr[i]+" "
        return ans.strip()
