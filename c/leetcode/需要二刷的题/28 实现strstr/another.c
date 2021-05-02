int strStr(char * haystack, char * needle){
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    if(needle[0] == '\0')
        return  0;
    int index = 0;
    while(haystack_len - index >= needle_len){
        if(haystack[index] == needle[0]){
            int j = 0;
            for(j = 0; j < needle_len; j++){
                if(haystack[index + j] != needle[j])
                    break;
            }
            if(j == needle_len)
                return index;
            else{
                index++;
                continue;
            }
        }
        index++;
    }
    return -1;
}d
//就离谱。。。把while的条件改了一下，就直接少了1000+ms，开玩笑吧……这力扣执行时间属实把我整懵逼了