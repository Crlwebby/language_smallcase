int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0,j = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                int *a = (int*)malloc(sizeof(int)*2);
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }
    return NULL;
}