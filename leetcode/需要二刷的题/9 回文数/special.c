int num(int x, int pos){
    return (int)(x / pow(10, pos - 1)) % 10;
}

bool isPalindrome(int x){
    if(x < 0) return false; // 负数作特殊处理
    int len = 0; // len是正整数的长度
    for( ; pow(10, len) <= x; len++); // 得到数字的位数
    int left = len, right = 1; // 类似双指针？
    while(left>right)
        if(num(x, left--) != num(x, right++)) return false;
    return true;
}

作者：whywait
链接：https://leetcode-cn.com/problems/palindrome-number/solution/ling-pi-xi-jing-de-jie-fa-ni-cong-wei-gan-shou-dao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//这个方法用num函数取数字的每一位，然后用left从右遍历，right从左遍历，逐位比较
//是个骚操作，但是效率好像不太行，因为调用了过多的函数和pow函数
//另外，这是个求得数字长度的好用方法，是for循环的别用，记录一下