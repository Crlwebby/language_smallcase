//练练快排
void quicksort(int* nums, int begin, int end){
    if(end <= begin){
        return;
    }
    int i = begin,j = end;
    int swap = nums[begin];
    while(i < j){
        while(i < j && nums[j] >= swap){
            j--;
        }
        if(j > i)
            nums[i] = nums[j];
        else
            break;
        
        while(i < j && nums[i]<swap){
            i++;
        }
        if(i < j)
            nums[j] = nums[i];
        else
            break;
    }
    nums[i] = swap;
    quicksort(nums,begin,i-1);
    quicksort(nums,i+1,end);
}
int findDuplicate(int* nums, int numsSize){
    quicksort(nums,0,numsSize-1);
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            return nums[i];
        }
    }
    return 0;
}
//简单来说，这次快排缺了几个思路
//1.不知道怎么把标记的数字换到中间去。我原本考虑的只是单纯的0-n遍历，遇见比标记小的数就交换，结果发现中间会漏了很多特别大的数字没有往后移动……
//2.不知道怎么使i与j最终相等，原本还在考虑额外添加一个变量，后来参考快排标答，发现只要在while里添加个(i<j)的条件即可……
//3.变量覆盖的时候没有对被覆盖的变量移位，就是nums[i++]和nums[j--]，这两部分很重要
//事实上，如果修改代码当然也可以，就是大while里的两个小while，判断语句可以改成>=或者<=，都不改的情况下，缺少了i++和j--有可能导致nums[i]=nums[j]=swap的情况
//而且根据排序的聚集效应，越到后面这一可能性越大，尤其是在数组中有重复数字的情况下，因此不能缺少
//测试成功，用>=替代条件然后去掉两个++是可以的