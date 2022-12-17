int findRepeatNumber(int* nums, int numsSize){
    int *a = (int*)malloc(numsSize * sizeof(int));
    memset(a,0,numsSize * sizeof(int));
    for(int i = 0;i<numsSize;i++){
        a[nums[i]]++;
    }
    for(int i = 0;i <numsSize;i++){
        if(a[i]>1)
            return i;
    }
    return NULL;
}

//不要考虑什么时间复杂度空间复杂度，直接桶排乱杀23333，简单粗暴，11.1MB，7.6%内存胜率，就是爽！

//自己的优化代码，区别不大
int findRepeatNumber(int* nums, int numsSize){
    int *a = (int*)malloc(numsSize * sizeof(int));
    memset(a,0,numsSize * sizeof(int));
    for(int i = 0;i<numsSize;i++){
        if(a[nums[i]]++>0){
            return nums[i];
        }
    }
    return NULL;
}