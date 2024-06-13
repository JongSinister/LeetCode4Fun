class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        word = ""
        ans = []
        for num in digits:
            word += str(num)
        word = str(int(word)+1)
        for i in range(len(word)):
            ans.append(int(word[i]))
        return ans
