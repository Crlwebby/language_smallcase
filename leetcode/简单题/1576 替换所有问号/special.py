class Solution:
    def modifyString(self, s: str) -> str:
        s1= 'abcdefghijklmnopqrstuvwxyz'
        res = list('0'+s+'0')
        i=1       
        while i<len(res)-1:
            if res[i]=='?':
                j=0
                while j<len(s1):
                    if s1[j] not in [res[i-1],res[i+1]]:
                        res[i]=s1[j]
                        break
                    j+=1
            i+=1
        return ''.join(res[1:-1])


作者：sunrise-z
链接：https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/solution/onzhi-zhen-cha-zhao-by-sunrise-z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#这个思路很赞，但是用C不是很好实现，记录一下
#简单来说，就是把字符串扩充两位，然后就不用考虑边界问题特殊处理了，思路瞬间清晰了很多