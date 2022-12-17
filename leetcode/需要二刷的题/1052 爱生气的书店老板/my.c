int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int max = 0, result = 0, temp = 0;
    for(int i = 0; i < customersSize; i++){
        if(!grumpy[i])
            result += customers[i];
        if(i <X){
            temp += customers[i] * grumpy[i];
            max = temp;
        }
        else{
            temp = temp + customers[i] * grumpy[i] - customers[i -X] * grumpy[i - X];
            if(temp > max)
                max = temp;
        }
    }
    return result + max;
}

//时间复杂度O(2n),空间复杂度O(1),但是分别为29.1%和40.1%……也未免过低了些
//思路还是比较清楚的，我觉得应该还是些优化上的小细节不太一样吧
//优化版本中，进一步理解题目意图，不再将customer设为负值，结果变为15.84%和100%……很魔幻
//两数交换用异或换成临时变量也是一样的结果，速度依旧很慢，内存消耗变多了

//原来是没学到滑动窗口的精髓
//滑动窗口没有必要每次都将窗口内的所有内容计算一遍
//而是将滑动的变化部分进行加减，大大提高了效率，从960ms减少至36ms