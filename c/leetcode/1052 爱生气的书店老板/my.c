int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int result = 0;
    for(int i = 0; i < customersSize; i++){
        if(grumpy[i])
            customers[i] = -1 * customers[i];
        result += customers[i]>0?customers[i]:0;
    }
    int min=0,temp=0;
    for(int i = 0; i <= customersSize - X; i++){
        temp = 0;
        for(int j = 0; j < X; j++){
            temp += customers[i + j]<0?customers[i + j]:0;
        }
        if(temp < min){
            temp = temp ^ min;
            min = temp ^ min;
            temp = temp ^ min;
        }
    }
    result -= min;
    return result;
}

//时间复杂度O(2n),空间复杂度O(1),但是分别为29.1%和40.1%……也未免过低了些
//思路还是比较清楚的，我觉得应该还是些优化上的小细节不太一样吧