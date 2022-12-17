char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max = len1>len2?len1:len2;
    int carry = 0;
    char *res = (char *)malloc(sizeof(char) * (max + 2));
    ++max;
    res[max--] = '\0';
    while(len1 || len2){
        if(len1 == 0){
            while(len2){
                res[max]=num2[--len2] + carry;
                carry = (res[max] - '0')/10;
                if(carry){
                    res[max] -= 10;
                }
                max--;
            }
            break;
        }
        if(len2 == 0){
            while(len1){
                res[max]=num1[--len1] + carry;
                carry = (res[max] - '0')/10;
                if(carry){
                    res[max] -= 10;
                }
                max--;
            }
            break;
        }
        res[max] = carry + num1[--len1] + num2[--len2] -'0';
        carry = (res[max] - '0')/10;
        if(carry){
            res[max] -= 10;
        }
        max--;
    }
    if(carry){
        res[max--] = carry + '0';
    }
    return res+max+1;
}
//麻烦的事情确实不少=。=，还是C语言处理字符串显得得心应手一点
//字符串确实是我的弱项啊，而且非常的弱=、= 看看这题，简单题，用debug，还乱七八糟写了四十行，是不是有点太麻烦了点……