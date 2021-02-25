char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}
//官方的思路，利用pairs这种伪哈希进行括号匹配
//如果是左括号的话返回0，在下面的判断中可以入栈；
//如果是右括号的话返回对应的左括号，看与栈内是否匹配，匹配的话栈指针--，否则false；
//思路清晰易懂，还有n%2 == 1和stk[n+1]的优化，学学人家！
bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


bool isValid(char * s){
    int len = strlen(s);
    char stack[len + 1];                        // 栈
    int top = -1;                               // 栈顶指针

    for (int i = 0; i < len; i++) {
        // 左括号入栈 -- 用相应的右括号入栈 -- 方便匹配
        if (s[i] == '(') stack[++top] = ')';
        else if (s[i] == '[') stack[++top] = ']';
        else if (s[i] == '{') stack[++top] = '}';
        
        // 不是左括号那就只有右括号了，栈空或不匹配则非法
        else if (top == -1 || stack[top] != s[i])
            return false;
        // 栈非空匹配 -- 出栈 -- 即栈顶指针往下移
        else
            top--;
    }

    // 如果遍历完字符串s后栈非空 -- 还有左括号未匹配 -- 非法
    // 如果遍历完字符串s后栈为空 -- 所有左括号匹配完 -- 合法
    return (top == -1);
}

作者：cao-mao-plasticine
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/cyu-yan-shi-xian-jian-ming-e-yao-fen-qing-kuang-xi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//这个方法是官方方法的另一种变形，用if语句代替哈希函数，用右括号入栈代替左括号入栈，区别不大，只是更不容易想到。