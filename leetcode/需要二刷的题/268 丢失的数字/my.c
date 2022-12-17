int missingNumber(int* nums, int numsSize){
    int a[numsSize + 1];
    for(int i = 0; i <= numsSize;i++){
        a[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        a[nums[i]] = 1;
    }
    int i;
    for(i = 0; i < numsSize + 1; i++){
        if(a[i] == 0)
            break;
    }
    return i;
}

//直接暴力……定义一个n+1的数组，扫一遍初始化，再扫一遍赋值，再扫一遍找结果。。。
//这怎么用位运算？怎么归到位运算的题目里去了？超出理解范围了