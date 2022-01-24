int lengthOfLongestSubstring(char * s){
    int pos[128] = {-1};//字符的范围是0-127，刚好可以以char作为字符下标进行寻址
    for(int i = 0; i < 128; i++)
        pos[i] = -1;
    int len = strlen(s);
    int max = 0,tmp_len=0;
    for(int i = 0; i < len; i++){
        if(pos[s[i]] == -1){
            pos[s[i]] = i;  //如果某个字母没有出现过，就保存该字母在字符串中的位置，方便之后出现重复后计算长度
            tmp_len++;
        }
        else{
            max = max > tmp_len ? max : tmp_len;
            for(int j = pos[s[i]]-1; j >= i-tmp_len; j--){
                pos[s[j]] = -1;
            }
            tmp_len = i - pos[s[i]];
            pos[s[i]] = i;
        }
    }
    max = max > tmp_len ? max : tmp_len;
    return max;
}

//5月份做的题=。=，九月份复习？甚至差点忘了自己做过这道题，反正现在好像不会了……