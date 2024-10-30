class Solution:
    def maximumSwap(self, num: int) -> int:
        n=list(str(num))
        for i in range(len(n)):
            submax="0"
            submaxidx=-1
            if n[i] == "9":continue
            for j in range(len(n)-1,i,-1):
                if n[j]>n[i] and n[j]>submax:
                    submax=n[j]
                    submaxidx=j
            if submaxidx!=-1:
                n[submaxidx],n[i]=n[i],n[submaxidx]
                break
        return int("".join(n))