bool isalnums(char s){
    return s>='A' && s<='Z' || s>='a' && s<='z' || s>='0' && s<='9';
}

char to_lower(char s){
    if(s >= 'A' && s <= 'Z')
        return s+32;
    return s;
}
bool isPalindrome(char *s){
    int len = strlen(s);
    int start = 0, end = len - 1;
    while(start < end){
        while(start < end && !isalnums(s[start])){
            start++;
        }
        while(start < end && !isalnums(s[end])){
            end--;
        }
        if(start < end){
            if(to_lower(s[start]) != to_lower(s[end]))
                return false;
            start++;
            end--;
        }
    }
    return true;
}
//感觉也不能完全算是官方答案吧，虽然非常像！
//好家伙，官方教你调API，一个是转小写，一个是判断是否是字母数字
//当然，把API分开后发现写的挺爽的，也没有我自己的那种，获取返回下标的麻烦问题在了，这教会我们要把功能点清晰的分开！
//70%+ 好了不少的样子，写的也很干净，十分快乐