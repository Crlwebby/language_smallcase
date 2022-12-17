char * makeGood(char * s){
    int length = strlen(s);
    if(length < 2)
        return s;
    int t = 0;
    char * result = malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++){
        if(t == 0)
            result[t++] = s[i];
        else if(abs(result[t-1] - s[i]) == 32)
            t--;
        else{
            result[t++] = s[i];
        }
    }
    result[t] = '\0';
    return result;
}
//用栈（队列？）写了一遍，逻辑干净了不少，就是资源消耗挺大23333