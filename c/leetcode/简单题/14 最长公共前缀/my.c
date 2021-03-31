char * longestCommonPrefix(char ** strs, int strsSize){

    if(strsSize == 0){
        return "";
    }
    char *prefix = strs[0];//因为是公共前缀，所以取第一个字符串必定包含前缀
    int i = 0;
    while(prefix[i] != '\0'){//循环条件
        for(int j = 0; j < strsSize; j++){
            if(strs[j][i] == '\0' || strs[j][i] != prefix[i]){  //纵向比较字符，如果字符不同或者某个字符串遍历完了，就把当前i的位置置0
                prefix[i--] = '\0'; //之所以要i--，是因为后面自己有个i++，为了避免置'\0'了还继续遍历
                break;
            }
        }
        i++;
    }
    return prefix;
}
//参考了题解的思路以后才自己写的，发现原来是这样来做的，好爽~
//题解有两种思路，横向比较和纵向比较，然后发现纵向比较的方法简直不要太舒服
//