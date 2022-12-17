char * convert(char * s, int numRows){
    if(numRows == 1)    //一行直接返回
        return s;
    int len = strlen(s);
    if(numRows >= len)  //如果行的高度比字符串长度还大，也可以直接返回
        return s;
    char *char_list[numRows];    //定义若干行字符串，用于保存结果
    int index[numRows];         //维护每行字符串的长度变量，方便后面取出字符
    for(int i = 0; i < numRows; i++){
        char_list[i] = (char *) malloc(sizeof(char) * (len/2+1));
        index[i] = 0;
    }
    int vector = -1;            //方向变量，刚开始向上，遇到0或n-1行变换方向。不失一般性，刚开始第一行之前设置为向上
    int row = 0;                //记录遍历时所在行的信息，通过row和vector决定接下来在第几行添加字符
    for(int i = 0; i < len; i++){
        char_list[row][index[row]++] = s[i];          //row是第几行，index[row]对应于第row行的最后一个位置
        if(row == 0 || row == numRows - 1){
            vector = -vector;
        }       
        row += vector;
    }
    char *result = (char *) malloc(sizeof(char) * (len+1)); //结果字符串，当然这里用s其实也是可以的……
    int temp = 0;   //temp用来作为字符串内的指针不断前移添加新字符
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < index[i]; j++){
            result[temp++] = char_list[i][j];
        }
    }
    result[len] = '\0';
    return result;
}

//这是按着官方思路抄的一个答案……
//真的不太会呀，啥叫毫无思路？那就是根本不知道该怎么写
//原本是想着先建一个nXn数组，然后再按z字形填充一遍。后来发现这个n我都没办法确定……太菜了
//定义一个方向向量vector，确定向上还是向下遍历，还是挺不错滴！