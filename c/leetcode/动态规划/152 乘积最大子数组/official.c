int max_1(int a, int b, int c){
    int max = a > b ? a : b;
    max = max > c ?  max : c;
    return max;
}

int min_1(int a, int b, int c){
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

int maxProduct(int* nums, int numsSize){
    int max[numsSize],min[numsSize];
    max[0] = nums[0];
    min[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        max[i] = max_1(max[i-1]*nums[i],min[i-1]*nums[i],nums[i]);
        min[i] = min_1(min[i-1]*nums[i],max[i-1]*nums[i],nums[i]);
    }
    int result = INT_MIN;
    for(int i = 0; i < numsSize; i++)
        result = result > max[i] ? result : max[i];
    return result;
}

//多个分类讨论……