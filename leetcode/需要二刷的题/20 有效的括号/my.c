bool correct(char * stack, int i){
    if(stack[i] == '{'){
        while(i > 0){
            if(stack[i] == '(' || stack[i] == '[')
                return false;
            i--;
        }
        return true;
    }
    else if(stack[i] == '['){
        while(i>0){
            if(stack[i] == '(')
                return false;
            i--;
        }
        return true;
    }
    return true;
}
bool isValid(char * s){
    int n = strlen(s);
    char stack[n];
    memset(stack,"",n * sizeof(char));
    int i = 0,index = 0;
    while(index < n){
        stack[i] = s[index];
        if(stack[i] == ')' || stack[i] == ']' || stack[i] == '}'){
            if(i == 0){
                return false;
            }
            if(stack[i]==')'&&stack[i-1]=='(' || stack[i]==']'&&stack[i-1]=='[' || stack[i]=='}'&&stack[i-1]=='{'){
                i--;
                index++;
                continue;
            }
            else{
                return false;
            }
        }
        i++;
        index++;
    }
    return i==0?true:false;
}
//我是真的麻了……完全面向实例的编程233333，疯狂根据报错的输入调整自己的代码，这样子好累
//而且！！它这个括号匹配不考虑大、中、小括号顺序的你知道吗？写了个函数没用，难顶嗷
//赶紧去学一学别人的思路吧，球球了！这种野蛮方式写的自己是真心难受