int GetVal(char s);
int romanToInt(char * s){
    int result = 0;
    int temp = GetVal(*s);
    s++;
    while( *s != '\0'){
        int val = GetVal(*s);
        if(temp < val){
            result -= temp;
        }
        else{
            result += temp;
        }
        temp = val;
        s++;
    }
    result += temp;
    return result;
}

int GetVal(char s){
    switch(s){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}
//整齐划一的case确实挺漂亮的~
//虽然简洁了很多，但是我觉得这个还是没有考虑脏数据的情况，由于小数字在大数字左边时的情况只有六种，但是这个样例程序明显没有考虑那么多
//仅供参考