char * freqAlphabets(char * s){
    char * result = malloc(sizeof(char) * 1000);
    int length = 0;
    int s_length = strlen(s);
    int bias;
    while(s_length > 2){    //有可能包含'#'的情况
        if( (*s == '1' || *s == '2') && *(s + 2) == '#'){   //有'#'的话，三个一组处理字符串
            bias = (*s - 0x30)*10 + (*(s+1)-0x30);
            result[length++] = 'a' + bias - 1;
            s = s + 3;
            s_length -= 3;
        }
        else{
            result[length++] = 'a' + *s-0x30 - 1;
            s += 1;
            s_length -= 1;
        }
    }
    while(s_length > 0){
        result[length++] = 'a' + *s -0x30 - 1;
        s += 1;
        s_length -= 1;
    }
    result[length] = '\0';
    return result;
}

//给我搞复杂了……但是字符串题确实没怎么练习过，不知道怎么处理这种需要一定回溯和预防的题目
//感觉处理边界条件处理的太多了，完全是没法复用的代码