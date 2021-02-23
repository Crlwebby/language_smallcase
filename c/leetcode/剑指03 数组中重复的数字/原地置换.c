int findRepeatNumber(int* nums, int numsSize){
    for(int i = 0;i<numsSize;i++){
        int temp = 0;
        if(i == nums[i])
            continue;
        if(nums[i] != nums[nums[i]]){
            temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
        else{
            return nums[i];
        }
    }
    return NULL;
}

//仅leetcode上看运行结果区别不大，但是分析来看这个原地置换的方法时间复杂度为O(n),空间复杂度为O(1)
//还是比我桶排好哈哈哈哈哈
//原地置换思路很巧，当然看个乐呵就行了