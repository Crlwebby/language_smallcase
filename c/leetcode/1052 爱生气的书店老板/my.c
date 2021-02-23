int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int result = 0;
    for(int i = 0; i < customersSize; i++){
        if(!grumpy[i])
            result += customers[i];
    }
    int max=0,temp=0;
    for(int i = 0; i <= customersSize - X; i++){
        temp = 0;
        for(int j = 0; j < X; j++){
            temp += grumpy[i + j]?customers[i + j]:0;
        }
        if(temp > max){
            temp = temp ^ max;
            max = temp ^ max;
            temp = temp ^ max;
        }
    }
    result += max;
    return result;
}

//时间复杂度O(2n),空间复杂度O(1),但是分别为29.1%和40.1%……也未免过低了些
//思路还是比较清楚的，我觉得应该还是些优化上的小细节不太一样吧
//优化版本中，进一步理解题目意图，不再将customer设为负值，结果变为15.84%和100%……很魔幻
//两数交换用异或换成临时变量也是一样的结果，速度依旧很慢，内存消耗变多了