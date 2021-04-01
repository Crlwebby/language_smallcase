char * freqAlphabets(char * s){
    char * result = malloc(sizeof(char) * 1000);
    int length = 0;
    int s_length = strlen(s);
    for(int i = 0; i < s_length; i++){
        if(i + 2 < s_length && s[i+2] == '#'){   //有可能包含'#'的情况,三个一组处理字符串
            result[length++] = 'a' + (s[i]-'0') * 10 + s[i+1]-'0' - 1;
            i += 2;
        }
        else{
            result[length++] = 'a' + *s-'0' - 1;
        }
    }
    result[length] = '\0';
    return result;
}

//这样看着干净多了，为什么我总是喜欢移动指针本身呢……用数组写不香吗？