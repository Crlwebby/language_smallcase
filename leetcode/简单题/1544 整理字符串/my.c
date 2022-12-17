char * makeGood(char * s){
    int length = strlen(s);
    if(length < 2)
        return s;
    int i = 0;
    while(s[i] != '\0'){
        if(abs(s[i] - s[i + 1]) == 32){
            for(int j = i; j < length -2; j++){
                s[j] = s[j + 2];
            }
            length -= 2;
            s[length]='\0';
            i==0?NULL:i--;
            continue;
        }
        i++;
        if(i > length - 2)
            break;
    }
    return s;
}

//面向样例编程……思路也还算清晰，就是有点点麻烦
//每次删除两个字母后，i指针要回退一位，检查移位后的字母；
//其它的就是检查边界条件和移位处理，画一画细心些也可以……看看官方有没有更清楚的解法

//官方做法确实很清楚，用栈来实现，用当前扫描的元素与栈内元素进行比较，如果符合条件出栈，不符合条件入栈，最后把栈内元素按顺序打印即可