int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int column = *AColSize;
    printf("Acolsize is %d\n",*AColSize);
    int temp[20]={0}, j = 0;
    for(int i = 0; i < ASize; i++){
        for(j = 0; j < column; j++){
            printf("i is %d, and j is %d\n",i,j);
            temp[column - j - 1] = A[i][j];
            printf("column-j-1 is %d, and temp[column-j-1] is %d\n",column-j-1,temp[column-j-1]);
            printf("A[i][j] is %d\n",A[i][j]);
        }
        for(j = 0; j < column; j++){
            A[i][j] = temp[j]==0?1:0;
        }
    }
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    return A;
}
//始终看不明白，明明都能全部运行完毕，到最后return给我报一个出错了？
//什么鬼一样的AddressSanitizer，还不能提供报错信息……裂开了啊
//自我调试，就是printf所有运行信息的时候都是对的，就这样吧……心累了

//看Debug commit……还是C语言没学好，看见二维指针就犯怵