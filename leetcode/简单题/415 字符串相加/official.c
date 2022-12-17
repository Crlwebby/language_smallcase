char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }
    // 计算完以后的答案需要翻转过来
    for (int i = 0; 2 * i < len; i++) {
        int t = ans[i];
        ans[i] = ans[len - i - 1], ans[len - i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/add-strings/solution/zi-fu-chuan-xiang-jia-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//题解简短精悍……优化的地方在于这样几个地方
//i,j是处理的不同吧，先减一的话要判断>=0，后减一的话判断>0
//主要是while循环里，用下标标记索引，并且用一个三元表达式把空值赋0，很简洁。
//这种方法就不用额外处理字符串长度不一样的问题了，而且它还把结果提前-'0'，用整数做处理，很方便
//还有不同的一点是它len从头开始的，最后弄个字符串反转，也可以，好理解的。