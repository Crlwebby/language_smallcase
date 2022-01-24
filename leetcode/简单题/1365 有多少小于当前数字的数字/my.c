/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++){
        result[i] = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[j] < nums[i])
                result[i]++;
        }
    }
    return result;
}

//这题一看就觉得是暴力……想也不想直接O(n^2)的算法来了……效率确实低，但是很清楚……
//排序的话，待会儿自己写个快排，然后把数组复制一份进行升序排序，把原数组的数字对应排序内的数字对应的下标找出来，就可以了
//想想感觉好麻烦……