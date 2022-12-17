/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int sum = 0;
    int *result = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        result[i] = sum;
    }
    *returnSize = numsSize;
    return result;
}

//别人的动态规划思路，忘了直接可以从本身数组入手的，多了个malloc
int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1){
        return nums;
    }
    for(int i = 1; i < numsSize; i++){
        nums[i] = nums[i] + nums[i - 1];
    }
    return nums;
}