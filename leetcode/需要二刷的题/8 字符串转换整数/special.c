#define START 0
#define SIGNED 1
#define NUMBER 2
#define END 3

int transition[4][4]={
    {START,SIGNED,NUMBER,END},
    {END,END,NUMBER,END},
    {END,END,NUMBER,END},
    {END,END,NUMBER,END}
};

int get_status(char s){
    if(s == ' ')
        return 0;
    if(s == '+' || s == '-')
        return 1;
    if(s >= 48 && s <= 57)
        return 2;
    return 3;
}

int myAtoi(char * s){
    long result = 0;
    int status = START;
    int sign = 1;
    while(1){
        char t = *s;
        status = transition[status][get_status(t)];
        if(status == SIGNED){sign = (*s) == '+' ? 1 : -1;}
        if(status == NUMBER){
            result = result * 10 + (*s - 48);
            if(result != (int)result){
                if(sign == 1)
                    result = INT_MAX;
                else
                    result = INT_MIN;
                break;
            }
        }
        if(status == END) break;
        s++;
    }
    result = result * sign;
    return result;
}

//也不知道这个算不算是自动机23333，就是参考了官方答案的自动机思想写出来的
//最关键的应该是最上面那个自动机状态转移表吧，就是transition数组
//当然，我写的很糙，让人看不明白，否则应该可以一目了然状态转移的。
//我是根据题解的自动机图写的数组。后面wa了几次的原因还是溢出没怎么处理过……溢出爆了好几次
//自动机写起来还是比自己瞎碰要爽一点，毕竟思路十分清晰，感觉很流畅