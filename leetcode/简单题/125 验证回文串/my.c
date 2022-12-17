int validate(char *s, int pos, bool flag){
    int len = strlen(s);
    while(pos < len && pos >= 0){
        if(s[pos] >= 'A' && s[pos] <= 'Z'){
            s[pos] += 32;
            return pos;
        }
        else if(s[pos] >= 'a' && s[pos] <= 'z' || s[pos] >= '0' && s[pos] <= '9')
            return pos;
        else{
            flag == true?pos++:pos--;
        }
    }
    return pos;
}
bool isPalindrome(char * s){
    int len = strlen(s);
    if(len <= 1)
        return true;
    int end = validate(s,len-1, false);
    int i = validate(s, 0, true);
    while(i >= 0 && i<len && end>=0 && end<len && i < end){
        if(s[i] != s[end])
            return false;
        i++,end--;
        i = validate(s,i,true);
        end = validate(s,end,false);
    }
    return true;
}
//感觉写的好累……不是啊，你回文串就老老实实回文串嘛！搁着非要加个忽略大小写、只考虑字母数字干嘛啊！
//这个条件就不得不让我加个validate验证函数，差点写炸了……
//只能说没怎么写过字符串，太难受了哇！
//哈哈哈哈哈哈哈神经病吧！就过了两个样例，还没提交测试呢就搁着写题解了，有点太蠢了吧……
//笑死，又改了好多行，第三行、第18、19行和第22行，多加了好多好多条件，然后击败5%，不愧是你！