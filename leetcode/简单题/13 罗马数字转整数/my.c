int romanToInt(char * s){
    int result = 0;
    while(*s != '\0'){
        switch (*s){
            case 'I':
                if(*(s+1) != '\0'){
                    if(*(s+1) != 'V' && *(s+1) != 'X'){
                        result += 1;
                    }
                    else{
                        result -= 1;
                    }
                }
                else{
                    result += 1;
                }
                s++;
                break;
            case 'X':
                if(*(s+1) != '\0'){
                    if(*(s+1) != 'L' && *(s+1) != 'C'){
                        result += 10;
                    }
                    else{
                        result -= 10;
                    }
                }
                else{
                    result += 10;
                }
                s++;
                break;
            case 'C':
                if(*(s+1) != '\0'){
                    if(*(s+1) != 'D' && *(s+1) != 'M'){
                        result += 100;
                    }
                    else{
                        result -= 100;
                    }
                }
                else{
                    result += 100;
                }
                s++;
                break;
            case 'V':
                result += 5;
                s++;
                break;
            case 'L':
                result += 50;
                s++;
                break;
            case 'D':
                result += 500;
                s++;
                break;
            case 'M':
                result += 1000;
                s++;
                break;
        }
    }
    return result;
}

//除了说又臭又长，还能干啥呢=。=
//swtich case方便简单，但是写了将近七十行
//看看有没有更简练的代码