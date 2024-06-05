class Solution:
    def reverse(self, x: int) -> int:
        a = str(x)
        tmp = ""
        if x < 0:
            tmp = "-"
            a = a[1:]
        a = a[::-1]
        val = int(tmp + str(int(a)))
        if val < -2**31 or val > 2**31-1:
            return 0
        return val
