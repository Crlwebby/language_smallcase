typedef struct {
    int *nums;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *temp;
    temp = (NumArray *)malloc(sizeof(NumArray));
    temp->nums = (int *)malloc(numsSize * sizeof(int));
    temp->numsSize = numsSize;
    for(int i = 0; i < numsSize; i++)
        temp->nums[i] = nums[i];
    return temp;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    for(; i<= j; i++){
        sum += obj->nums[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
    obj = NULL;
}

//我没想到这么慢……原本以为应该是常规思路，求和不就都加起来吗
//结果耗时280ms，只打败了7.04%……就离谱，我倒要看看这咋优化