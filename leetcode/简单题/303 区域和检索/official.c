//打扰了，是我辣鸡，我不配！
//没读清楚题目，原来是要调用若干次求和的啊，按我这种大概就是n^2的复杂度了……
//于是似乎又有了动态规划的思路，就是把之前求过的内容存起来，要用的时候调用即可

typedef struct {
    int *nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *temp;
    temp = (NumArray *)malloc(sizeof(NumArray));
    temp->nums = (int *)malloc((numsSize + 1) * sizeof(int));
    temp->nums[0] = 0;
    for(int i = 0; i < numsSize; i++)
        temp->nums[i + 1] = temp->nums[i] + nums[i];
    return temp;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj->nums[j + 1] - obj->nums[i];
}

void numArrayFree(NumArray* obj) {
    free(obj);
    obj = NULL;
}