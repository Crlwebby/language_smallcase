int lengthOfLastWord(char * s){
    int len = 0;
    while(*s != '\0'){
        if(*s == ' '){
            while(1){
                //这个while(1)是为了处理奇怪的样例的……谁能想到字符末尾给你几个空格恶心一下呢？
                if(*s == ' ')
                    s++;
                else
                    break;
            }
            if(*s != '\0')
                len = 0;
        }
        else{
            len++;
            s++;
        }
    }
    return len;
}

//这题就感觉莫名其妙……简单题现在有点不是很想做了
//总之题目感觉描述的模糊不清的