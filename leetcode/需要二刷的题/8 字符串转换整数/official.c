int myAtoi(char * s){
    int i = 0,flag = 1;
    long returnNumber = 0;
    //空格;
    while(s[i] == ' '){
        i++;
    }
    //正负号;
    if(s[i] == '-' || s[i] == '+'){
        flag = 44-s[i++];    
    }
    //计算;
    while(s[i] >= '0' && s[i] <= '9'){
        returnNumber = returnNumber*10 + s[i++] - '0';
        if(returnNumber != (int)returnNumber) break;    //判断溢出;
    }
    returnNumber *= flag;
    return returnNumber==(int)returnNumber?(int)returnNumber:returnNumber<0?-2147483648:2147483647;
}

作者：eternalee
链接：https://leetcode-cn.com/problems/string-to-integer-atoi/solution/0ms-100-cyu-yan-lao-shi-ren-suan-fa-16xi-wl57/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//这题确实也不需要自动机，因为状态确实很少，多考虑考虑应该是能考虑明白的
//就像这个题解一样，空格和+/-号，只有出现在前面的才需要考虑，丢弃无用前导空格，然后处理+/-号
//后面再出现这俩货的话，直接退出输出结果就行，哪用考虑什么空格、+/-在中间的问题，这么麻烦！