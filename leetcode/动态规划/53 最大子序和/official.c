int maxSubArray(int* nums, int numsSize){
    int m[numsSize];
    m[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        m[i] = m[i-1] + nums[i];
        if(m[i] < nums[i])
            m[i] = nums[i];
    }
    int max = INT_MIN;
    for(int i = 0; i < numsSize; i++)
        max = max < m[i] ? m[i] : max;
    return max;
}

//关键始终是在写出递推公式上，如何分析最优子结构是个关键呀！