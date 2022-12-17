int myAtoi(char * s){
    int result = 0;
    int sign = 0;
    int flag = 0;
    //flag用于记录是否处于一个数字中间，避免遇见数字里面夹杂着符号位的特殊情况
    while(*s != '\0'){
        if(*s == ' '){
            if(flag == 1)
            //数字中间有空格，直接断掉输出前面的数字
                break;
        }
        else{
            if(*s == '+' || *s == '-'){
                if(flag == 1)
                //数字中间遇见符号也断掉
                    break;
                else{
                    flag = 1;
                    sign = (*s == '+') ? 1 : -1;
                    //如果是加号符号位为1，否则是-1
                }
            }
            else if(*s > 57 || *s < 48)
            //遇见非数字直接退出循环
                break;
            else{
                flag = 1;
                long long temp = result;
                temp = temp * 10 + (*s - 48);
                result = temp;
                if(result != temp)
                //如果有发生溢出，直接返回INT_MAX或INT_MIN
                {
                    sign = (sign == 0)?1:sign;
                    if(sign == 1){return INT_MAX;}
                    if(sign == -1){return INT_MIN;}
                }
            }
        }
        s++;
    }
    sign = (sign == 0)?1:sign;
    result *= sign;
    return result;
    //没有符号位的情况下，sign没有被赋值过，默认为1
}

//没啥说的，提交六次才过一个，不做人了……条件乱七八糟，写的太难受了
//就是菜，爬就完事儿了