int strStr(char * haystack, char * needle){
    int len = strlen(needle);
    if(needle[0] == '\0')
        return  0;
    int index = 0;
    while(haystack[index] != '\0'){
        if(haystack[index] == needle[0]){
            int j = 0;
            for(j = 0; j < len; j++){
                if(haystack[index + j] != needle[j])
                    break;
            }
            if(j == len)
                return index;
            else{
                index++;
                continue;
            }
        }
        index++;
    }
    return -1;
}

//属实没想到……普通思路嘛确实还是简单的，但是效率有点害怕，怎么就一千多毫秒了啊……您到底是用了什么样例啊
//确实，这是朴素字符串匹配算法，当初的还是有些印象的，就是每次一个个字符遍历，然后遍历相应的字串
//优化也就模模糊糊有点KMP的印象了，估计回去可以好好再研究一下KMP算法