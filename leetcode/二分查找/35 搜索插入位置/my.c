int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    for(; i < numsSize; i++){
        if(nums[i] >= target)
            break;
    }
    return i;
}
//只能说，啥也不想说……这还能更简洁吗？
//标签里好像有二分查找搞一波，但我觉得没什么必要……8行的代码还要啥自行车嘛！